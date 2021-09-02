#include<bits/stdc++.h>
using namespace std;


void print(vector<vector<char>> &arr)
{
    for(int j=0;j<10;j++)
    {
        for(int i=0;i<10;i++)
        {
            cout<<arr[j][i];
        }
        cout<<"\n";
    }
}

bool canPlaceHorizontally(vector<vector<char>> &arr,string word, int i, int j)
{
    /* if left side is valid and it is not '+'  then return false*/
    if(j-1>=0 and arr[i][j-1]!='+')
    {
        return false;
    }

    /* on right side at the end of available spaces there should be + to ensure that the word fits perfectly, else return false*/
    else if(j + word.size() < arr[0].size() and arr[i][j + word.size()]!='+') 
    {
        return false;
    }


    for(int p=0;p<word.size();p++)
    {

        if(j + p >= arr[0].size()) /* check if available space size is less than word size */
        {
            return false;
        }


        if(arr[i][j + p]=='-' or arr[i][j + p]==word.at(p))
        {
            continue;
        }
        else
        {
            /* no empty space or character which matches word's character*/
            return false;
        }
    }

    return true;
}

bool canPlaceVertically(vector<vector<char>> &arr,string word, int i, int j)
{
    /* if top side is valid and it is not '+'  then return false*/
    if(i-1>=0 and arr[i-1][j]!='+')
    {
        return false;
    }

    /* on down side at the end of available spaces there should be + to ensure that the word fits perfectly, else return false*/
    else if(i + word.size() < arr.size() and arr[i+word.size()][j]!='+') 
    {
        return false;
    }


    for(int p=0;p<word.size();p++)
    {

        if(j + p >= arr[0].size()) /* check if available space size is less than word size */
        {
            return false;
        }


        if(arr[i+p][j]=='-' or arr[i+p][j]==word.at(p))
        {
            continue;
        }
        else
        {
            /* no empty space or character which matches word's character*/
            return false;
        }
    }

    return true;
}



/* Horizontal */
vector<bool> placeHorizontally(vector<vector<char>> &arr,string word, int i, int j)
{
    vector<bool> wordPlaced(word.size(),false);
 for(int p=0;p<word.size();p++)
 {
    if(arr[i][j+p]=='-')
    {
        arr[i][j+p]=word.at(p);
        wordPlaced[p]=true;
    }
 }  

 return wordPlaced; 
}

void unPlaceHorizontally(vector<vector<char>> &arr,vector<bool> &wordPlaced, int i, int j)
{
    for(int p=0;p<wordPlaced.size();p++)
    {
        if(wordPlaced[p]==true)
        {
            arr[i][j+p]='-';
        }
    }
}




/* VERTICAL*/

vector<bool> placeVertically(vector<vector<char>> &arr,string word, int i, int j)
{
    vector<bool> wordPlaced(word.size(),false);
 for(int p=0;p<word.size();p++)
 {
    if(arr[i+p][j]=='-')
    {
        arr[i+p][j]=word.at(p);
        wordPlaced[p]=true;
    }
 }  

 return wordPlaced; 
}

void unPlaceVertically(vector<vector<char>> &arr,vector<bool> &wordPlaced, int i, int j)
{
    for(int p=0;p<wordPlaced.size();p++)
    {
        if(wordPlaced[p]==true)
        {
            arr[i+p][j]='-';
        }
    }
}



void solve( vector<vector<char>> &arr,vector<string> &words,int index)
{
    if(index==words.size())
    {
        cout<<"here";
        print(arr);
        return;
    }

    string word=words[index];
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            if(arr[i][j]=='-' or arr[i][j]==word.at(0))
            {
                if(canPlaceHorizontally(arr,word,i,j))
                {
                    vector<bool> wordPlaced=placeHorizontally(arr,word,i,j);
                    solve(arr,words,index+1);
                    unPlaceHorizontally(arr,wordPlaced,i,j);
                }
                if(canPlaceVertically(arr,word,i,j))
                {
                    vector<bool> wordPlaced=placeVertically(arr,word,i,j);
                    solve(arr,words,index+1);
                    unPlaceVertically(arr,wordPlaced,i,j);
                }
            }
        }
    }
}



int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    
    vector<vector<char>> arr;
    
    for(int i=0;i<10;i++)
    {
        vector<char> temp;
        for(int j=0;j<10;j++)
        {
            char x;
            cin>>x;
            temp.push_back(x);
        }
        arr.push_back(temp);
    }
    
    
    vector<string> words;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        string str;
        cin>>str;
        words.push_back(str);
    }
    
    // for(int i=0;i<words.size();i++)
    // {
    //     cout<<words[i]<<"\n";
    // }

    solve(arr,words,0);
}














/* JAVA CODE */

import java.io.*;
import java.util.*;

public class Main {

    public static boolean canPlaceHorizontal(char[][] grid, int r, int c, String word) {
        // left check
        if(c > 0 && grid[r][c - 1] != '+') {
            return false;
        } 
        // right check
        if(c - 1 + word.length() >= grid[0].length) { 
            return false;
        }

        if((c - 1 + word.length() < grid[0].length - 1) && (grid[r][c + word.length()] != '+')) {
            return false;
        }
        for(int j = 0; j < word.length(); j++) {
            if(grid[r][j + c] != '-' && grid[r][j + c] != word.charAt(j)) {
                return false;
            }
        }
        return true;
    }

    public static boolean canPlaceVertical(char[][] grid, int r, int c, String word) {
        // top check
        if(r > 0 && grid[r - 1][c] != '+') {
            return false;
        } 
        // bottom check
        if(r - 1 + word.length() >= grid.length) { 
            return false;
        }

        if((r - 1 + word.length() < grid.length - 1) && (grid[r + word.length()][c] != '+')) {
            return false;
        }
        for(int i = 0; i < word.length(); i++) {
            if(grid[i + r][c] != '-' && grid[i + r][c] != word.charAt(i)) {
                return false;
            }
        }
        return true;
    }

    public static boolean[] placeHorizontal(char[][] grid, int r, int c, String word) {
        boolean[] status = new boolean[word.length()];
        for(int j = 0; j < word.length(); j++) {
            if(grid[r][c + j] == '-') {
                grid[r][c + j] = word.charAt(j);
                status[j] = true;
            }
        }
        return status;
    }

    public static boolean[] placeVertical(char[][] grid, int r, int c, String word) {
        boolean[] status = new boolean[word.length()];
        for(int i = 0; i < word.length(); i++) {
            if(grid[r + i][c] == '-') {
                grid[r + i][c] = word.charAt(i);
                status[i] = true;
            }
        }
        return status;
    }

    public static void unplaceHorizontal(char[][] grid, int r, int c, boolean[] status) {
        for(int i = 0; i < status.length; i++) {
            if(status[i] == true) {
                grid[r][c + i] = '-';
            }
        }
    }

    public static void unplaceVertical(char[][] grid, int r, int c, boolean[] status) {
        for(int i = 0; i < status.length; i++) {
            if(status[i] == true) {
                grid[r + i][c] = '-';
            }
        }
    }


    public static void solution(char[][] grid, String[] words, int vidx){
        if(vidx == words.length) {
            // print
            print(grid);
            return;
        }

        String word = words[vidx];
        for(int i = 0; i < grid.length; i++) {
            for(int j = 0; j < grid[0].length; j++) {
                if(grid[i][j] == '-' || grid[i][j] == word.charAt(0)) {
                    // horizontal try
                    if(canPlaceHorizontal(grid, i, j, word)) {
                        // place 
                        boolean[] status = placeHorizontal(grid, i, j, word);
                        solution(grid, words, vidx + 1);
                        // unplace
                        unplaceHorizontal(grid, i, j, status);
                    }
                    // vertical try
                    if(canPlaceVertical(grid, i, j, word)) {
                        // place
                        boolean[] status = placeVertical(grid, i, j, word);
                        solution(grid, words, vidx + 1);
                        // unplace
                        unplaceVertical(grid, i, j, status);
                    }
                }   
            }
        }
    }
    public static void print(char[][] arr){
        for(int i = 0 ; i < arr.length; i++){
            for(int j = 0 ; j < arr.length; j++){
                System.out.print(arr[i][j]);
            }
                  System.out.println();
        }
        
    }
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        char[][] arr = new char[10][10];
        for(int i = 0 ; i < arr.length; i++){
            String str = scn.next();
            arr[i] = str.toCharArray();
        }
        int n = scn.nextInt();
        String[] words = new String[n];
        for(int i = 0 ; i  < words.length; i++){
            words[i] = scn.next();
        }
        solution(arr,words,0);
//      print(arr);

    }
}