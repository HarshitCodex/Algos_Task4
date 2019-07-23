    #include<bits/stdc++.h>

    using namespace std;

    int main(){
      int n;
      while(cin >> n){
        string s;cin >> s;
        vector<int > a(n,1);

        bool flag = true;
        while(flag){
          //    print(a);
          flag = false;
          for(int i = 0;i<n-1;i++){
    	if(s[i] == '='){
    	  if( a[i] != a[i+1]){
    	    if(a[i] > a[i+1]){
    	      a[i+1] = a[i];
    	    }else{
    	      a[i] = a[i+1];
    	    }
    	    flag = true;
    	  }
    	}else if(s[i] == 'R'){
    	  if( a[i] >= a[i+1]){
    	    a[i+1] = a[i] + 1;
    	    flag = true;
    	  }
    	}else if(s[i] == 'L'){
    	  if( a[i] <= a[i+1]){
    	    a[i] = a[i+1] + 1;
    	    flag = true;
    	  }
    	}
          }
        }
        for(int i = 0;i<n;i++){
          cout << a[i] << " ";
        }
        cout << endl;

      }
      return 0;
    }
