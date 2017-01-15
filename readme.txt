Scripts:

./plot compiled from plot.cpp, plot.hpp, and utils.hpp:
Takes argument of .root input file with ntuples of events. Outputs .root file with various histograms and scatter plots for different hadrons, with file located at ./output/[generator_name].root

./compare_tag_proportions_generators compiled from compare_tag_proportions_generators.cpp and utils.hpp:
Takes argument of hadron number to examine, followed by names of generators (to access output files from ./plot). Outputs .pdf file with bar chart of tag efficiencies for different generators, and selected MV2C20 cut.

./compare_tag_proportions_hadrons compiled from compare_tag_proportions_hadrons.cpp and utils.hpp:
Takes argument of generator to examine, followed by numbers of hadrons. Outputs .pdf file with bar chart of tag efficiencies for different hadrons, and selected MV2C20 cut. Also outputs .pdf files of bar chart of tagged jets and total jets, one with logarithmic scale, and one with linear scale.

./simple_tag_proportions compiled from simple_tag_proportions.cpp, simple_tag_proportions.hpp, and utils.hpp:
Takes argument of .root input file with ntuples of events. Outputs .pdf for bar chart of tag efficiency for specified generator and hadron number. 
