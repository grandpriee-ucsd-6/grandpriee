int * gradient_filter(int * raw){
  int * filtered = new int[LEN];
  for(int i = 0; i<LEN -1 ; i++){
    filtered[i] = raw[i+1] - raw[i];
  }
  filtered[LEN -1] = 0;
  return filtered;
}
