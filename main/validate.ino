int validate(int width, int * width_array, int loop_count, int sum){
    if(loop_count < 20) return 1; //start validating after 20 loops; 
    double mean = sum / loop_count;
    double var = 0.0;
    for(int i = 0; i < loop_count; i++){
       var += (width_array[i] - mean) * (width_array[i] - mean);
     }
    var /= loop_count;
    double std = sqrt(var) ;
    if (width > mean + std) return 2; //wider than usual;
    else if (width < mean - std) return 0; //narrower than usual;
    else return 1; //usual
}
