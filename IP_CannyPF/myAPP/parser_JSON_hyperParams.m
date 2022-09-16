fname = 'hyperParams.json'; 
data = load_JSON(fname);

% parameters of CannyPF
GaussSize = uint8(3);
VMGradient = 70.0;

% parameters: prior knowledge
angle_expect = pi/2;

% Paser the hyperparameter from JSON file.
% hyperparameter: scale
scale_start = data.scale.start;
scale_step = data.scale.step;
scale_end = data.scale.end;

% hyperparameter: windowWidth
windowWidth_start = data.windowWidth.start;
windowWidth_step = data.windowWidth.step;
windowWidth_end = data.windowWidth.end;

% hyperparameter: windowStepSize
windowStepSize_start = data.windowStepSize.start;
windowStepSize_step = data.windowStepSize.step;
windowStepSize_end = data.windowStepSize.end;


% hyperparameter: angle_tolerance
angle_tolerance_start = (data.angle_tolerance.start)/180*pi;
angle_tolerance_step = (data.angle_tolerance.step)/180*pi;
angle_tolerance_end = (data.angle_tolerance.end)/180*pi;


% hyperparameter: decision_criterion
decision_criterion = data.decision_criterion;
decision_criterion_size = size(decision_criterion, 1);


% hyperparameter: need to be decided after training
% 1) after training: prior_mandrel_diameter

% 2) after training: lenth_threshold

% 3) after training: number_threshold




