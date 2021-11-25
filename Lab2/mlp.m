%%Written by Nikita Belooussov and Roberto Ariosa
%% Load data

clear all;
load('Input.mat')
load('Output.mat')

count = gpuDeviceCount;
if count > 1
    gpuDevice(1)
end

rng(1);

%% Train

funcs = {...
    {'logsig', 'logsig', 'mse'} ; ...
    {'logsig','softmax','crossentropy'}...
};

k = 0;
c = containers.Map;

for i = 1:numel(funcs)
    for n_hidden = [50, 200, 500]
        for ratios = [0.8 0.4 0.1; 0.1 0.2 0.1; 0.1 0.4 0.8]
            d = [0 0 0];
            for j = [1 2 3]
                % Train
                net = build_nn(Input, Output, n_hidden, funcs{i}{1}, funcs{i}{2}, funcs{i}{3}, ratios(1), ratios(2), ratios(3));
                [net, tr] = train(net, Input, Output, 'useGpu', 'no');

                % Calculate accuracy
                X_test = Input(:, tr.testInd);
                y_test = Output(:, tr.testInd);
                y_pred = net(X_test);
                [~, y_pred_max] = max(y_pred, [], 1);
                [~, y_test_max] = max(y_test, [], 1);
                accuracy = mean(y_test_max == y_pred_max);
                d(j) = accuracy;

                % Save plots
                %plotperform(tr);
                %print('-dpng', ['perform' num2str(plot_number) '.png'])
                %plottrainstate(tr);
                %print('-dpng', ['trainstate' num2str(plot_number) '.png'])
        
                disp([funcs{i}{3} num2str(n_hidden) num2str(ratios(1)) num2str(k)]);
                k = k + 1;
            end
            d(end + 1) = mean(d);
            c([funcs{i}{3} num2str(n_hidden) num2str(ratios(1)) num2str(k - 1)]) = d;
        end
    end
end

%% Select the best classifier

I = '';
max = 0;
for j = keys(c)
    vl = values(c,j);
    %disp(j{1})
    if vl{1}(4) > max && startsWith(j{1}, 'mse')
        I = j;
        max = vl{1}(4);
        %disp(vl{1}(4))
        %disp(j)
    end
end

I2 = '';
max2 = 0;
for j = keys(c)
    vl = values(c,j);
    %disp([j{1} " " vl{1}(4)])
    if vl{1}(4) > max2 && startsWith(j{1}, 'cross')
        I2 = j;
        max2 = vl{1}(4);
        %disp(vl{1}(4))
        %disp(j)
    end
end

max
max2
I
I2

%% Build neural network
function [net] = build_nn(Input, Output, hidden_units, tfh, tfo, pf, tr, vr, ts)
    net = feedforwardnet(hidden_units);
    
    % Set functions
    net.outputs{:}.processFcns = {};
    net.layers{1}.transferFcn = tfh;
    net.layers{2}.transferFcn = tfo;
    net.performFcn = pf;

    % Set hidden units
    net.layers{1}.size = hidden_units;
    
    % Set training function
    net.trainFcn = 'traingdx';
    net.trainParam.max_fail = 6;
    %net.trainParam.lr = lrv;
    %net.trainParam.mc = mcv;
    
    % Set dividing parameters
    net.divideFcn = 'dividerand';
    net.divideParam.trainRatio = tr;
    net.divideParam.valRatio = vr;
    net.divideParam.testRatio = ts;
    
    % Set input / output size
    net = configure(net, Input, Output);


    %net.trainParam.min_grad = 1e-7;
    
    % Set training params
    net.plotFcns = {'plotperform','plottrainstate','ploterrhist', 'plotregression', 'plotfit'};
end