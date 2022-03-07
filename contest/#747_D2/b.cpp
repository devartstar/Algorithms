    vpii cols(m+1);
    bool ok;
    bool finalok = false;
    bool finalok1 = false;
    f1(j,m){
        ok = false;
        f1(i,n-1){
            if(arr[i][j] == arr[i+1][j]){
                ok = true;
                cols[j] = mp(i,i+1);
                break;
            }
        }
        if(!ok){
            break;
        }
    }
    if(!ok) finalok = false;
    else    finalok = true;

    bool ok1, ok2;
    int a, b;
    vector<pair<pii, int>> ans;
    f1(j,m-1){
        ok1 = true, ok2 = false;
        f1(i,n){
            if(arr[i][j] != arr[i][j+1]){
                ok1 = false;
                break;
            }
            if(j<m){
                if(arr[i][j] == arr[i][j+1] && arr[i][j] == arr[i+1][j+1] && arr[i][j] == arr[i+1][j]){
                    ok2 = true;
                    b = i;
                }
            }
        }
        if(ok1 && ok2){
            a = j;
            break;
        }
    }
    finalok1 = ok1 && ok2;
    if(finalok1 && finalok){
        for(int j=1; j<= a-1; j++){
            for(int i=1; i<=cols[j].ff-1; i++){
                ans.pb({{i,j},arr[i][j]});
            }
            for(int i=n; i<=cols[j].ss+1; i--){
                ans.pb({{i-1,j},arr[i][j]});
            }
        }
        for(int j=m; j>=a+2; j--){
            for(int i=1; i<=cols[j].ff-1; i++){
                ans.pb({{i,j-1},arr[i][j]});
            }
            for(int i=n; i>=cols[j].ss+1; i--){
                ans.pb({{i-1,j-1},arr[i][j]});
            } 
        }

        for(int i=1; i<=b-1; i++){
            ans.pb({{i,a}, arr[i][a]});
        }
        for(int i=n; i>=b+2; i--){
            ans.pb({{i-1,a}, arr[i][a]});
        }
        ans.pb({{b,a}, arr[b][a]});

        cout<<(int)ans.size()<<endl;
        for(pair<pii,int> x : ans)
            cout<<x.ff.ff<<" "<<x.ff.ss<<" "<<x.ss<<endl;
 
    }