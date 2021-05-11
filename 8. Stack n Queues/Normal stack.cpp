#include<bits/stdc++.h>
using namespace std;



   class CustomStack {
    int[] data;
    int tos;

    CustomStack(int cap) {
      data = new int[cap];
      tos = -1;
    }

    int size() {
      // write ur code here
    }

    void display() {
      // write ur code here
    }

    void push(int val) {
      // write ur code here
    }

    int pop() {
      // write ur code here
    }

    int top() {
       // write ur code here
    }
  };

  int main()
  {
    // BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int n;
    cin>>n;
    CustomStack st = new CustomStack(n);

    string s;
    getline(cin,s);
    
    while(s.compare("quit") == false){
      if(s.find("push")==0)
      {

        string d=" ";
        int val=stoi(s.substr(s.find(d)));
        st.push(val);

      }
      
       else if(str.startsWith("pop"))
       {
        int val = st.pop();
        if(val != -1){
          System.out.println(val);
        }
      } 

      else if(str.startsWith("top")){
        int val = st.top();
        if(val != -1){
          System.out.println(val);
        }
      }
      else if(str.startsWith("size")){
        System.out.println(st.size());
      } 
      else if(str.startsWith("display")){
        st.display();
      }
      str = br.readLine();
    }
  }
