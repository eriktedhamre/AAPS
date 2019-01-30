#include <bits/stdc++.h>
//#define REP(var, k) for (int var = 0; var < (int) k; ++var)
using namespace std;

//using vi=vector<int>;


vector<int> cover(pair<double, double> interval, vector<pair<double, double> > intervals){
    //Result vector
    vector<int> indices;
    double left_point = interval.first;
    double right_point = interval.second;
    // Iterator used throughout search
    vector<pair<double, double> >::iterator it = intervals.begin();
    while(left_point < right_point){
        // Current best interval for current left most point
        vector<pair<double, double> >::iterator best;
        // Second element of best interval
        double distance_covered = 0;
        // Pick the interval that covers the left most point
        // and as much of the rest as possible
        while( it != intervals.end() && left_point >= it->first){
            // This can probably be done better
            // We need something to compare with
            // For the first time the point is covered by the interval
            if (distance_covered == 0){
                best = it;
                distance_covered = abs(left_point - best->second);
            }
            else if(abs(left_point - it->second) > distance_covered){
                best = it;
                distance_covered = abs(left_point - best->second);
            }
            it = it + 1;
        }
        if(distance_covered == 0){
            // Add a -1 as index to the result vector
            // It's impossible to cover
            indices.push_back(-1);
            break;
        }
        else{
            // Move the left most point
            left_point = best->second;
            printf("best first %lf, best second %lf \n", best->first, best->second);
            // Add best's index to the result vector
            indices.push_back(best - intervals.begin());
            int index = best - intervals.begin();
            printf("best_index %d \n", index);
            // Check if we have covered the entire intervall
            // Is done in the while-loop
            // reset distance_covered
            distance_covered = 0;
            // Restart search with new left most point
            // Where we left off
        }  
    }
    if(*indices.end() == -1){
        vector<int> bad;
        bad.push_back(-1);
        return bad;
    }
    return indices;
}

/*
// Should try a general solution
vector<int> cover(pair<double, double> interval, Iterator.begin(), Iterator.end())
*/


bool intervalCmp(const pair<double, double> &a, const pair<double, double> &b){
    if(a.first != b.first){
        return a.first < b.first;
    }
    else{
        return a.second < b.second;
    }
}

int main() {

    //Current interval
    double lower;
    double upper;
    int number_of_intervals;
    
    vector<int> result;

    while(scanf("%lf %lf", &lower, &upper)){
        pair<double, double> interval = make_pair(lower, upper);
        vector<pair<double, double> > intervals;
        scanf("%d", &number_of_intervals);
        for(int i = 0; i < number_of_intervals; i++){
            pair<double, double> curr_interval;
            double curr_lower;
            double curr_upper;
            scanf("%lf %lf", &curr_lower, &curr_upper);
            printf("curr_lower: %lf , curr_upper %lf \n", curr_lower, curr_upper);
            curr_interval = make_pair(curr_lower, curr_upper);
            intervals.push_back(curr_interval);
        }
        // Sorting in ascending order on first element and then second element
        sort(intervals.begin(), intervals.end(), intervalCmp);
        vector<int> curRes = cover(interval, intervals);
        // Push back current result,
        // unsure if we need to keep it until
        // all input is read or if we can simply print it
        if(*curRes.end() == -1){
            result.push_back(-1);
        }
        else{
            result.push_back(curRes.size());
            result.insert(result.end(), curRes.begin(), curRes.end());
        }
        printf("%lu curRes.size() \n", curRes.size());
        for(int i = 0; i < curRes.size(); i++){
            if(i == 0){
                printf("%d number of intervals \n", curRes[0]);
            }
            else{
                printf("%d ", curRes[i]);
            }
        }
        /*
        for(int i = 0; i < intervals.size(); i++){
            printf("First: %lf Second: %lf \n", intervals.at(i).first, intervals.at(i).second);
        }
        */
    };
    //
    //
    //
    
    


    return 0;
}
