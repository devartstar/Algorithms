#include <bits/stdc++.h>
using namespace std;

// class Store{
//     private:


// };

class Item{
    public:
        string ItemName;
        int ItemPricePerUnit;
        float ItemQuantity = 0.0;
};

class Perishable{
    public:
        vector<string> perishableItems;

        float getShippingPricePerishable(float q){
            if(q<5.0){
                return 0;
            }else{
                return 5*(q-5);
            }
        }
};

class NonPerishable{
    public:
        vector<string> NonperishableItems;

        float getShippingPriceNonPerishable(float q){
            if(q<4.0){
                return 0;
            }else{
                return 2*(q-4);
            }
        }
};

class Cart{
    public:
        vector<string> pitemBought;
        vector<int> pitemQuantity;
        vector<float> pitemPrice;
        vector<string> npitemBought;
        vector<int> npitemQuantity;
        vector<float> npitemPrice;

        float getTotalperishableQuantity(){
            float qnt = 0.0;
            for(int i=0; i<(int)pitemQuantity.size(); i++){
                qnt += pitemQuantity[i];
            }
            return qnt;
        }

        float getTotalnonperishableQuantity(){
            float qnt = 0.0;
            for(int i=0; i<(int)npitemQuantity.size(); i++){
                qnt += npitemQuantity[i];
            }
            return qnt;
        }

        float perishableTotal(Item item[100001], int cnt){
            float ptotalPrice = 0.0;
            for(int k=0; k<(int)pitemBought.size(); k++){
                for(int i=0; i<cnt; i++){
                    if(item[i].ItemName==pitemBought[k]){
                        pitemPrice[k] = pitemQuantity[k]*item[i].ItemPricePerUnit;
                        ptotalPrice += pitemPrice[k];
                        break;
                    }
                }
            }
        }

        float nonperishableTotal(Item item[100001], int cnt){
            float ptotalPrice = 0.0;
            for(int k=0; k<(int)pitemBought.size(); k++){
                for(int i=0; i<cnt; i++){
                    if(item[i].ItemName==pitemBought[k]){
                        pitemPrice[k] = pitemQuantity[k]*(item[i].ItemPricePerUnit/item[i].ItemQuantity);
                        ptotalPrice += pitemPrice[k];
                        break;
                    }
                }
            }
        }
};

int main(){


    // an array of items - storea all the items present in the store
    Item items[100005];


    // getting input from user
    int count = 0;
    string s = "";
    while(s!="End"){
        cin>>s;
        if(s=="End"){
            break;
        }
        items[count].ItemName = s;
        cin>>items[count].ItemPricePerUnit;
        cin>>items[count].ItemQuantity;
    }

    Perishable p;
    NonPerishable np;
    for(int i=0; i<count; i++){
        if(items[i].ItemQuantity==0.0){
            p.perishableItems.push_back(items[i].ItemName);
        }else{
            np.NonperishableItems.push_back(items[i].ItemName);
        }
    }

    Cart c;
    string it = "";
    while(it!="Checkout"){
        cin>>it;
        float q;
        cin>>q;
        // checking if it is perishable item
        bool peri = false;
        for(string s : p.perishableItems){
            if(s==it){
                peri = true;
                c.pitemBought.push_back(it);
                c.pitemQuantity.push_back(q);
            }
        }
        if(peri == false){
            c.npitemBought.push_back(it);
            c.npitemQuantity.push_back(q);
        }
    }

    float price1 = c.perishableTotal(items, count);
    float price2 = c.nonperishableTotal(items, count);

    float totprice = price1+price2;

    // to calc shipping price
    float q1 = c.getTotalperishableQuantity();
    float q2 = c.getTotalnonperishableQuantity();

    float pshipping = p.getShippingPricePerishable(q1);
    float npshipping = np.getShippingPriceNonPerishable(q2);

    float totalShipping = pshipping + npshipping;

    float final_total = totprice + totalShipping;

    //////////////////////////////////////////////////////////
    // DISPLAYING THE FINAL OUTPUT


    for(int i = 0; i<(int)c.pitemBought.size(); i++){
        cout<<c.pitemBought[i]<<"     "<<c.pitemPrice[i]<<endl;
    }
    for(int i = 0; i<(int)c.npitemBought.size(); i++){
        cout<<c.npitemBought[i]<<"     "<<c.npitemPrice[i]<<endl;
    }
    cout<<"Shipping                      "<<totalShipping<<endl;
    cout<<"Total                      "<<final_total<<endl;
}