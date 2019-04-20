int dist_med(int * nums){
  int maxv = nums[0], minv = nums[0];
  int maxin = 0,minin = 0;
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
  int realMed = (maxin + minin)/2;
  int med = LEN / 2;
  return realMed - med;
}
