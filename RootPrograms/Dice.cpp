
int getDiceFaceFromRandom(double probability, double *faces_probabilities, int array_size){
    int dice_face = 1;
    for(int i = 0; i < array_size; i++){
        faces_probabilities[i];
        if(probability <= faces_probabilities[i]){
            break;
        }
        probability -= faces_probabilities[i];
        dice_face++;
    }
    cout << dice_face << endl;
    return dice_face;
}

void fillHistogramData(TH1F *histogram,  double *faces_probabilities, int array_size){
    //Random number generator
    TRandom1* r = new TRandom1();
    //local variables
    int dice_face = 0;
    double random_val = 0;

    for(int i = 0; i < 1000; i++){
        random_val = r->Rndm();
        dice_face = getDiceFaceFromRandom(random_val, faces_probabilities, array_size);
        histogram->Fill(dice_face);
    }
    histogram->GetYaxis()->SetRangeUser(0,1000);
    histogram->SetFillColor(kRed);
    histogram->Draw();
}

void Dice(){
    //Local variables
    int faces = 2;
    double *faces_probabilities = new double[faces];

    //Create canvas for histograms
    TCanvas* canvas = new TCanvas("canvas", "canvas", 1000, 800);
    canvas->Divide(2);
    /************ two-faces equally probable dice histogram ********************************/
    //switch canvas pad
    canvas->cd(1);
    faces_probabilities[0] = 0.5;
    faces_probabilities[1] = 0.5;
    //Create histogram
    double binEdges[] = {0,0.9,1.1,1.9,2.1,2.9};
    TH1F* h = new TH1F("DHist_1", "two-faces equally probable dice histogram", faces * 2 + 1, binEdges);
        //histogram name - h 
        //Hist title - Histogram
        //Number of bins - 10
        // x low value
        // x up value
        //fill faces probabilities
    //draw histogram
    fillHistogramData(h,faces_probabilities,faces);
    h->SetFillColor(kAzure-4);

    TLegend* legend = new TLegend(0.1,0.7,0.48,0.9);
    //legend->SetHeader("Dice histograms","C"); // option "C" allows to center the header
    legend->AddEntry(h,"dice equally probable","f");
    gStyle->SetLegendTextSize(0.03);
    legend->Draw();

    /************two-faces 60%,40% dice histogram ********************************/
    //switch canvas pad
    canvas->cd(2);
    //fill faces probabilities
    faces_probabilities[0] = 0.4;
    faces_probabilities[1] = 0.6;
    //Create histogram
    TH1F* h2 = new TH1F("DHist_2", "two-faces 40%,60% dice histogram", faces * 2 + 1, binEdges);
    fillHistogramData(h2,faces_probabilities,faces);
    h2->SetFillColor(kGreen-9);

    legend = new TLegend(0.1,0.7,0.48,0.9);
    //legend->SetHeader("Dices histograms","C"); // option "C" allows to center the header
    legend->AddEntry(h2,"40%-60% dice","f");
    legend->Draw();
    /************ six-faces dice histogram ********************************/
    /*
    //switch canvas pad
    canvas->cd(3);
    //fill faces probabilities
    faces = 6;
    faces_probabilities = new double[faces];
    faces_probabilities[0] = 0.166;
    faces_probabilities[1] = 0.166;
    faces_probabilities[2] = 0.166;
    faces_probabilities[3] = 0.166;
    faces_probabilities[4] = 0.166;
    faces_probabilities[5] = 0.17;
    double binEdges2[] = {0,0.9,1.1,1.9,2.1,2.9,3.1,3.9,4.1,4.9,5.1,5.9,6.1,6.9};
    //Create histogram
    TH1F* h3 = new TH1F("DHist_3", "six-faces equally probable dice histogram", faces * 2 + 1, binEdges2);
    fillHistogramData(h3,faces_probabilities,faces);
    */
    /************ six-faces different prob dice histogram ********************************/
    //switch canvas pad
    /*canvas->cd(4);
    //fill faces probabilities
    faces_probabilities[0] = 0.10;
    faces_probabilities[1] = 0.15;
    faces_probabilities[2] = 0.30;
    faces_probabilities[3] = 0.20;
    faces_probabilities[4] = 0.15;
    faces_probabilities[5] = 0.10;
    //Create histogram
    TH1F* h4 = new TH1F("DHist_4", "six-faces 10,15,30,20,15,10 dice histogram", faces *2 + 1, binEdges2);
    fillHistogramData(h4,faces_probabilities,faces);
    */
   
}


