function [data] = load_JSON(jsonFile)
fid = fopen(jsonFile); raw = fread(fid,inf); str = char(raw'); fclose(fid); 
data = jsondecode(str);
end

