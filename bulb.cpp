int Solution::bulbs(vector<int> &A) {

    int n = A.size(),cnt =0;


    bool flipped = false;

    for(int i=0;i<n;i++){



        if((!flipped && A[i]) || (flipped && !A[i]))    continue;

        


        else{

            A[i] = 1;

            cnt++;

            flipped = !flipped;

        }

    }

    return cnt;

}
