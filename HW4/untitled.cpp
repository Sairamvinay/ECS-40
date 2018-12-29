ifstream f("Facilities.txt");

string line;

while(getline(f,line)){
  
  Facility * fp = new Facility(line);
  facilities.push_back(fp);
}
f.close();









ifstream file("Runways.txt");
string line1;

while(getline(file,line1)){
  Runway * rp= new Runway(line1);
  runways.push_back(rp);
}
file.close();





 vector<Runway*>::iterator it = runways.begin();

    while (it!=runways.end())
    {
      
 
      it = find_if(it,runways.end(),SiteNumber(a->site_number()));

      if (it!=runways.end()) {
        if ((*it)->length() >= min_runway_length)
          good_runways.push_back(*it);

        it++;

      }
      
      
    }



