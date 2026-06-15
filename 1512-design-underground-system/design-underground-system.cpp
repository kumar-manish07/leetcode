class UndergroundSystem {
public:

    map<string,pair<int,int>> track;
    map<int,pair<string,int>> in;

    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        in[id]={stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        string startStation=in[id].first;
        string endStation=stationName;
        string journey=startStation + "-" + endStation;
        int totalTime=t-(in[id].second);
        if(track.find(journey)==track.end())   track[journey]={totalTime,1};
        else{
            track[journey].first+=totalTime;
            track[journey].second++;
        }
    }
    
    double getAverageTime(string startStation, string endStation) {
        string journey=startStation + "-" + endStation;
        int totalTime=track[journey].first;
        int count=track[journey].second;
        double avg = (double)totalTime/count;
        return avg;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */