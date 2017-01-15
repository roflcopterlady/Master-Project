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

// Script outputs plots of proportion of b-tagged jets, number of b-tagged jets, and total number of jets containing specified hadrons for a given generator.
// First argument is generator to examine, and following arguments are hadrons to examine.
int main(int argc, char* argv[]) {

	// Select MV2C20 cut to use, from position in vector (0-3)
	int cut_pos;
	cout << "Select tag cut number: ";
	cin >> cut_pos;
	cout << endl;

	// Get string of MV2C20 cut
	TString tag_cut = Form("%f", tag[cut_pos]);

	// Get string of generator to use, from argument
	TString generator = argv[1];

	vector<TString> hlabels; // Vector to contain hadron labels being examined

	// Vector of number of tagged, untagged, total jets, and proportion of tagged jets.
	vector<float> tagged_numbers, total_numbers;
	vector<float> tagged_prop;

	// Input file from specified generator
	TFile * f = new TFile("output/" + generator + ".root");

	// Loop across arguments of hadrons
	for (int i=2; i<(argc); i++) {

		// Add hadron label to vector
		hlabels.push_back(argv[i]);

		float tagged_number, untagged_number, total_number;
		
		// Load histogram of number of tagged, untagged jets from file
		TH1 * loaded_hist = (TH1F*) gDirectory->Get("tagged_prop_" + tag_cut + "_" + argv[i]);

		// Get number of tagged, untagged jets, and calculate total
		tagged_number = loaded_hist->GetBinContent(loaded_hist->FindBin(1.0));
		untagged_number = loaded_hist->GetBinContent(loaded_hist->FindBin(0.0));
		total_number = tagged_number + untagged_number;

		// Add tagged, total numbers to vector
		tagged_numbers.push_back(total_number);
		total_numbers.push_back(total_number);
		
		// Add proportion of tagged jets to vector
		tagged_prop.push_back(tagged_number / total_number);
		
	}

	// Get number of hadrons being examined
	int nx = hlabels.size();


	// Proportion plot:

	// Canvas, pads, legend for plot of tagged proportions
	TCanvas *cb_prop = new TCanvas("cb_prop","cb_prop",8000,4000);

	TPad * left_pad_prop = new TPad("left_pad_prop", "left_pad_prop", 0.005, 0.005, 0.695, 0.995);
	TPad * right_pad_prop = new TPad("right_pad_prop", "right_pad_prop", 0.705, 0.005, 0.995, 0.995);
	left_pad_prop->Draw();
	right_pad_prop->Draw();

	TLegend * legend_prop = new TLegend(0.1,0.1,0.9,0.9, "", "NDC");
	legend_prop->SetTextSize(0.05);

	// Set up bar chart for tagged proportion
	left_pad_prop->cd();
	left_pad_prop->SetGrid();
	gStyle->SetHistMinimumZero();
	TH1F *h1b_prop = new TH1F("h1b_prop", "Proportions of Tagged and Jets - Generator " + generator + " - MV2C20 Cut " + tag_cut, nx, 0, nx);
	h1b_prop->SetFillColor(4);
	h1b_prop->SetBarWidth(0.8);
	h1b_prop->SetBarOffset(0.1);
	h1b_prop->SetStats(0);
	h1b_prop->SetMinimum(0);
	h1b_prop->SetMaximum(1.1);

	// Set bin content for each bar in chart
	for (int i=1; i<=nx; i++) {
		h1b_prop->SetBinContent(i, tagged_prop.data()[i-1]);
		h1b_prop->GetXaxis()->SetBinLabel(i, hlabels[i-1]);
	}

	// Draw bar chart and add entry to legend 
	h1b_prop->Draw("b");
	legend_prop->AddEntry(h1b_prop, "Tagged", "f");
   
	// Draw legend and print bar chart
	right_pad_prop->cd();
	legend_prop->Draw();	
	cb_prop->Print("tag_props_" + generator + "_" + tag_cut + ".pdf");
	
	
	// Number Plot:

	// Set up canvas, pads, and legend for bar chart of numbers of tagged jets, and total jets.
	TCanvas *cb_number = new TCanvas("cb_number","cb_number",8000,4000);	
	
	TPad * left_pad_number = new TPad("left_pad_number", "left_pad_number", 0.005, 0.005, 0.695, 0.995);
	TPad * right_pad_number = new TPad("right_pad_number", "right_pad_number", 0.705, 0.005, 0.995, 0.995);
	left_pad_number->Draw();
	right_pad_number->Draw();
	
	TLegend * legend_number = new TLegend(0.1,0.1,0.9,0.9, "", "NDC");
	legend_number->SetTextSize(0.05);
	
	// Get maximum bin content, to set maximum of y-axis in bar chart
	float max_number = *std::max_element(total_numbers.begin(), total_numbers.end());

	// Set up bar chart for tagged numbers of jets.
	left_pad_number->cd();
	left_pad_number->SetGrid();
	gStyle->SetHistMinimumZero();
	TH1F *h1b_number = new TH1F("h1b_number", "Numbers of Tagged and Total Jets - Generator " + generator + " - MV2C20 Cut " + tag_cut, nx, 0, nx);
	h1b_number->SetFillColor(4);
	h1b_number->SetBarWidth(0.4);
	h1b_number->SetBarOffset(0.1);
	h1b_number->SetStats(0);
	h1b_number->SetMinimum(0.1);
	h1b_number->SetMaximum(1.05 * max_number);

	// Set bin contents for tagged jets
	for (int i=1; i<=nx; i++) {
		h1b_number->SetBinContent(i, tagged_numbers.data()[i-1]);
		h1b_number->GetXaxis()->SetBinLabel(i, hlabels[i-1]);
	}

	// Draw bar chart and add to legend
	h1b_number->Draw("b");
	legend_number->AddEntry(h1b_number, "Tagged", "f");
	
	// Set up bar chart for total numbers of jets
	TH1F *h3b_number = new TH1F("h3b_number", "Numbers of Tagged and Total Jets - Generator " + generator + " - MV2C20 Cut " + tag_cut, nx, 0, nx);
	h3b_number->SetFillColor(46);
	h3b_number->SetBarWidth(0.4);
	h3b_number->SetBarOffset(0.1);
	h3b_number->SetStats(0);

	// Set bin contents for total numbers of jets
	for (int i=1;i<=nx;i++) h3b_number->SetBinContent(i, total_numbers.data()[i-1]);

	// Draw bar chart and add entry to legend
	h3b_number->Draw("b same");
	legend_number->AddEntry(h3b_number, "Total", "f");
	
	// Draw legend
	right_pad_number->cd();
	legend_number->Draw();
	
	// Print bar chart for numbers of jets
	cb_number->Print("tag_numbers_" + generator + "_" + tag_cut + ".pdf");
	
	// Set logarithmic scale, and print again
	left_pad_number->SetLogy();
	cb_number->Print("tag_numbers_log_" + generator + "_" + tag_cut + ".pdf");
	
	return 1;
}
