%% Import data from text file.
% Script for importing data from the following text file:
%% Initialize variables.
filename = 'clearingtimeresults.log';
delimiter = {'\t',' '};
startRow = [2,6,10,14,18,22,26,30];
endRow = [2,6,10,14,18,22,26,30];

%% Format string for each line of text:
formatSpec = '%*s%s%[^\n\r]';

%% Open the text file.
fileID = fopen(filename,'r');

%% Read columns of data according to format string.
% This call is based on the structure of the file used to generate this
% code. If an error occurs for a different file, try regenerating the code
% from the Import Tool.
textscan(fileID, '%[^\n\r]', startRow(1)-1, 'WhiteSpace', '', 'ReturnOnError', false);
dataArray = textscan(fileID, formatSpec, endRow(1)-startRow(1)+1, 'Delimiter', delimiter, 'ReturnOnError', false);
for block=2:length(startRow)
    frewind(fileID);
    textscan(fileID, '%[^\n\r]', startRow(block)-1, 'WhiteSpace', '', 'ReturnOnError', false);
    dataArrayBlock = textscan(fileID, formatSpec, endRow(block)-startRow(block)+1, 'Delimiter', delimiter, 'ReturnOnError', false);
    dataArray{1} = [dataArray{1};dataArrayBlock{1}];
end

%% Close the text file.
fclose(fileID);

%% Allocate imported array to column variable names
wallTime = dataArray{:, 1};

%% Clear temporary variables
clearvars filename delimiter startRow endRow formatSpec fileID block dataArrayBlock dataArray ans;

%% Analysis of walltime against number of cores
% Get number of different trials run (i.e. number of times code was tested)
numTrials = length(wallTime);
numCores = 1:1:numTrials;
% Preallocate vector of walltimes in seconds for faster computation in loop
wallTimeSec = zeros(1, numTrial);
% Preallocate vector of speed up in seconds for faster computation in loop
speedUp = zeros(1, numTrial);
% Preallocate vector of ca. serial fractions for faster computation in loop
serialFraction = zeros(1, numTrial);
for i=1:numTrial
    % Split the string within the cell into substrings partitioned by 'm'
    % and 's'
    wallTime{i} = strsplit(wallTime{i}, {'m', 's'});
    % Get the number of minutes in the total wall time for each trial
    wallTimeMin = str2double(wallTime{i}{1});
    % Get the number of seconds in the total wall time for each trial and
    % add the minutes to it in units of seconds
    wallTimeSec(i) = str2double(wallTime{i}{2}) + wallTimeMin*60;
    % Get the Speed Up given by formula in lecture
    speedUp(i) = wallTimeSec(1)/wallTimeSec(i);
    % Get the serial fraction by rearranging for 'f' from the formula for
    % S given in lecture
    serialFraction(i) = (1/speedUp(i) - 1/i)/(1 - 1/i);
end
% Get the mean serial fraction to report for assignment
serialFractionMean = mean(serialFraction(2:end));
%% Create plot of relative speed against time
figure
plot(speedUp)
title('Speed Up against Number of Processors')
xlabel('Number of Processors')
ylabel('Speed Up')
% Plot saved seperately
%% 
results = [numCores; wallTimeSec; speedUp];
fileID = fopen('results.txt', 'w');
fprintf(fileID,'%1s %10s %8s\n', 'P', 'Wall Time', 'Speed Up');
fprintf(fileID,'%1.0f %10.4f %8.4f\n', results);
fprintf(fileID, 'The mean serial fraction is %1.4f', serialFractionMean);
fclose(fileID);