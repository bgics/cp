#!/bin/env bash

file_name=$1

echo "#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); 
}
" > "$file_name.cpp"

hx "$file_name.cpp"
