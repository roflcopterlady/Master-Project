#include <iostream>
#include <vector>

#include "TString.h"
#include "TFile.h"
#include "TH1.h"
#include "TCanvas.h"
#include "TPad.h"
#include "TStyle.h"
#include "TLegend.h"

#include "utils.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::vector;

// Compares proportions of tagged jets for different event generators, with a given hadron
// First argument is hadron to examine, and following arguments are generators.
int main(int argc, char* argv[]) {

	// Select MV2C20 cut to use, from position in vector (0-3)
	int cut_pos;
	cout << "Select tag cut number: ";
	cin >> cut_pos;
	cout << endl;

	// Get string of MV2C20 cut
	TString tag_cut = Form("%f", tag[cut_pos]);

	// Get string of hadron to examine, from argument
	TString hlabel = argv[1];

	vector<TString> generators; // Vector to contain generators being examined

	vector<float> tagged_prop; // Vector to contain proportions of tagged jets

	TFile * f; // Declaring object for input files

	// Loop across arguments of generators
	for (int i=2; i<(argc); i++) {

		generators.push_back(argv[i]); // Add generator name to vector

		// Load input file for generator
		f = new TFile("output/" + TString(argv[i]) + ".root");

		// Load histogram for hadron being examined
		TH1 * loaded_hist = (TH1F*) gDirectory->Get("tagged_prop_" + tag_cut + "_" + hlabel);

		// Get number of tagged and untagged jets from histogram
		float tagged_number = loaded_hist->GetBinContent(loaded_hist->FindBin(1.0));
		float untagged_number = loaded_hist->GetBinContent(loaded_hist->FindBin(0.0));

		// Add tagged proportion of jets to vector
		tagged_prop.push_back(tagged_number / (tagged_number + untagged_number));

	}

	// Get number of generators being examined
	int nx = generators.size();

	// Canvas, pads, legend for plot of tagged proportions
	TCanvas *cb = new TCanvas("cb","cb",8000,4000);

	TPad * left_pad = new TPad("left_pad", "left_pad", 0.005, 0.005, 0.695, 0.995);
	TPad * right_pad = new TPad("right_pad", "right_pad", 0.705, 0.005, 0.995, 0.995);
	left_pad->Draw();
	right_pad->Draw();

	TLegend * legend = new TLegend(0.1,0.1,0.9,0.9, "", "NDC");
	legend->SetTextSize(0.05);

	// Set up bar chart for tagged proportion
	left_pad->cd();
	cb->SetGrid();
	gStyle->SetHistMinimumZero();
	TH1F *h1b = new TH1F("h1b", "Proportions of Tagged and Untagged Jets - Hadron " + hlabel + " - MV2C20 Cut " + tag_cut, nx, 0, nx);
	h1b->SetFillColor(4);
	h1b->SetBarWidth(0.8);
	h1b->SetBarOffset(0.1);
	h1b->SetStats(0);
	h1b->SetMinimum(0);
	h1b->SetMaximum(1.1);

	// Set bin content for each bar in chart
	for (int i=1; i<=nx; i++) {
		h1b->SetBinContent(i, tagged_prop.data()[i-1]);
		h1b->GetXaxis()->SetBinLabel(i, generators[i-1]);
	}

	// Draw bar chart and add legend entry
	h1b->Draw("b");
	legend->AddEntry(h1b, "Tagged", "f");

	// Draw legend
	right_pad->cd();
	legend->Draw();

	// Print bar chart
	cb->Print("tag_props_" + hlabel + "_" + tag_cut + ".pdf");

	return 1;
}
