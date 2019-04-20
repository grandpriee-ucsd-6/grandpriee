int * edges(int * nums){
  int maxv = nums[0], minv = nums[0];
  int maxin = 0,minin = 0;
//  for (int i = 0; i < LEN; i++) {
//    if (nums[i] > maxv) {
//      maxv = nums[i];
//      maxin = i;
//    }
//  }
//
//  for (int i = 0; i < maxin; i++) {
//    if (nums[i] > minv) {
//      minv = nums[i];
//      minin = i;
//    }
//  }
//
//  int * range = new int[2];
//  range[0] = minin;
//  range[1] = maxin;
  
  for(int i = 0; i<LEN ; i++){
    if(maxv <= nums[i]){
      maxv = nums[i];
      maxin = i;   
    }
    if(minv > nums[i]){
      minv = nums[i];
      minin = i;
    }
  }
  int * range = new int[2];
  range[0] = maxin;
  range[1] = minin;
  return range;
}
