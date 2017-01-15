# Makefile to compile fortran and c++ guru code
# Gavin Hesketh (ghesketh@fnal.gov), February 2007.
C++ = g++
C_FLAGS = -g

ROOTCFLAGS=$(shell root-config --cflags) 
ROOTLIBS= $(shell root-config --libs)

all:  plot compare_tag_proportions_generators compare_tag_proportions_hadrons simple_tag_proportions
#TriggerAnalysis PlotResult

clean:                                              
	rm plot Draw Draw_tim Reweight

plot: plot.cpp plot.hpp utils.hpp
	$(C++) $(ROOTCFLAGS) $(C_FLAGS) plot.cpp  -o plot  $(ROOTLIBS) 

compare_tag_proportions_generators: compare_tag_proportions_generators.cpp 
	$(C++) $(ROOTCFLAGS) $(C_FLAGS) compare_tag_proportions_generators.cpp  -o compare_tag_proportions_generators  $(ROOTLIBS) 

compare_tag_proportions_hadrons: compare_tag_proportions_hadrons.cpp 
	$(C++) $(ROOTCFLAGS) $(C_FLAGS) compare_tag_proportions_hadrons.cpp  -o compare_tag_proportions_hadrons  $(ROOTLIBS) 

simple_tag_proportions: simple_tag_proportions.cpp simple_tag_proportions.hpp utils.hpp
	$(C++) $(ROOTCFLAGS) $(C_FLAGS) simple_tag_proportions.cpp  -o simple_tag_proportions  $(ROOTLIBS) 

Draw: Draw.cpp utils.hpp
	$(C++) $(ROOTCFLAGS) $(C_FLAGS) Draw.cpp  -o Draw  $(ROOTLIBS) 

Draw_tim: Draw_tim.cpp utils.hpp
	$(C++) $(ROOTCFLAGS) $(C_FLAGS) Draw_tim.cpp  -o Draw_tim  $(ROOTLIBS) 

Reweight: Reweight.cpp utils.hpp
	$(C++) $(ROOTCFLAGS) $(C_FLAGS) Reweight.cpp  -o Reweight  $(ROOTLIBS) 


