void Histogram(){
    delete gROOT->FindObject("h");
    TH1F* h = new TH1F("h", "Histogram", 10, 0, 10);
    //histogram name - h 
    //Hist title - Histogram
    //Number of bins - 10
    // x low value
    // x up value
    TRandom1* r = new TRandom1();
    int random_val = 0;
    for(int i = 0; i < 1000; i++){
        random_val = r->Rndm() * 10;
        random_val = random_val % 10;
        h->Fill(random_val);
    }
    h->Draw();
}