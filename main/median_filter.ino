int * median_filter(int * raw){
  int * filtered = new int[LEN];
  for(int i = 1; i<LEN -1 ; i++){
    filtered[i] = MEDIAN(raw[i-1],raw[i],raw[i+1]);
  }
  filtered[0] = MEDIAN(raw[0],raw[0],raw[1]);
  filtered[LEN - 1] = MEDIAN(raw[LEN-2],raw[LEN-1],raw[LEN - 1]);
  return filtered;
}
