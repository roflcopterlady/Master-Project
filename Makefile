# Makefile to compile fortran and c++ guru code
# Gavin Hesketh (ghesketh@fnal.gov), February 2007.
C++ = g++
C_FLAGS = -g

ROOTCFLAGS=$(shell root-config --cflags) 
ROOTLIBS= $(shell root-config --libs)

all: simple_tag_proportions plot_for_btagging compare_generators bin_values
#  plot compare_work_points compare_tag_proportions_generators compare_tag_proportions_hadrons
#TriggerAnalysis PlotResult

clean:                                              
	rm simple_tag_proportions

plot: plot.cpp plot.hpp utils.hpp
	$(C++) $(ROOTCFLAGS) $(C_FLAGS) plot.cpp  -o plot  $(ROOTLIBS) 

compare_work_points: compare_work_points.cpp utils.hpp
	$(C++) $(ROOTCFLAGS) $(C_FLAGS) compare_work_points.cpp  -o compare_work_points  $(ROOTLIBS) 

compare_tag_proportions_generators: compare_tag_proportions_generators.cpp 
	$(C++) $(ROOTCFLAGS) $(C_FLAGS) compare_tag_proportions_generators.cpp  -o compare_tag_proportions_generators  $(ROOTLIBS) 

compare_tag_proportions_hadrons: compare_tag_proportions_hadrons.cpp 
	$(C++) $(ROOTCFLAGS) $(C_FLAGS) compare_tag_proportions_hadrons.cpp  -o compare_tag_proportions_hadrons  $(ROOTLIBS) 

simple_tag_proportions: simple_tag_proportions.cpp simple_tag_proportions.hpp utils.hpp
	$(C++) $(ROOTCFLAGS) $(C_FLAGS) simple_tag_proportions.cpp  -o simple_tag_proportions  $(ROOTLIBS) 

plot_for_btagging: plot_for_btagging.cpp plot_for_btagging.hpp utils.hpp
	$(C++) $(ROOTCFLAGS) $(C_FLAGS) plot_for_btagging.cpp  -o plot_for_btagging  $(ROOTLIBS)

compare_generators: compare_generators.cpp compare_generators.hpp utils.hpp plot_for_btagging.hpp plot_for_btagging.cpp
	$(C++) $(ROOTCFLAGS) $(C_FLAGS) compare_generators.cpp  -o compare_generators  $(ROOTLIBS)

bin_values: bin_values.cpp bin_values.hpp utils.hpp plot_for_btagging.hpp plot_for_btagging.cpp
	$(C++) $(ROOTCFLAGS) $(C_FLAGS) bin_values.cpp  -o bin_values  $(ROOTLIBS)

Draw: Draw.cpp utils.hpp
	$(C++) $(ROOTCFLAGS) $(C_FLAGS) Draw.cpp  -o Draw  $(ROOTLIBS) 

Draw_tim: Draw_tim.cpp utils.hpp
	$(C++) $(ROOTCFLAGS) $(C_FLAGS) Draw_tim.cpp  -o Draw_tim  $(ROOTLIBS) 

Reweight: Reweight.cpp utils.hpp
	$(C++) $(ROOTCFLAGS) $(C_FLAGS) Reweight.cpp  -o Reweight  $(ROOTLIBS) 
