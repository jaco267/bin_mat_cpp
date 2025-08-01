#include "examples.h"
using namespace nc::indexing; 
void ex10(){ //* init Tensor : zeros, ones arange,  reshape, toVec, toMat
  cout<<"--init Tensor with vector data and vector shape"<<endl;
  vector<int> zz = zeros_vec<int>(16); zz[0]=3; zz[5]=9;
  vector<int> shape = {4,4};
  Tensor<int> t0 (zz,shape); //* or just : Tensor<int> v0 {zz,/*shape*/{4,4}};
  t0.info();
  cout<<"--init Tensor with vector data and {shape}"<<endl;
  vector<float> zf = arange_vec<float>(0,6);
  Tensor<float> t1 (zf, {2,3}); //todo  t1(zf, {2,-1})??
  t1.info();
  cout<<"--init Tensor with {data} and {shape}"<<endl; 
  Tensor<float> t2 ({-1,2,5,
                      7,8,9}, {2,3}); //todo  t1(zf, {2,-1})??
  t2.info();
  //** init Tensor directly */
  cout<<"----Tensor init directly----"<<endl;
  cout<<"--zeros--"<<endl;
  Tensor<float> t3 = zeros<float> ({2,3});  
  t3.info();
  cout<<"---ones---"<<endl;
  t3 = ones<float> ({2,2});
  t3.info();
  cout<<"--arange--"<<endl;
  t3 = arange<float>(-1,6);  
  t3.info();
}
void ex11(){
  Tensor<float> T0 = zeros<float> ({4,3}); 
  T0.info();
  cout<<"---reshape T0----"<<endl;
  vector<int> new_shape = {2,-1};
  Tensor<float> T0_r = T0.reshape(new_shape);
  T0_r.info();
  mat<float> mm = T0_r.toMat();
  cout<<"Tensor 2 matrix:\n";
  mm[0][0] = 3;
  print_mat(mm);
  mm[0][1] = 4;
  vector<float> one_vec6 = ones_vec<float>((int)mm[0].size());
  mm.push_back(one_vec6);
  cout<<"Matrix 2 tensor:\n";
  T0_r.fromMat(mm);
  T0_r.info();
  Tensor<float> newv2 = T0.reshape({-1});
  newv2.info();
  vector<float> vv = newv2.toVec();
  cout<<"vector version:";
  print_vec(vv);
  cout<<"3 dim tensor";
  newv2 = newv2.reshape({2,3,2});
  newv2.info();
}
void ex12(){
  nc::indexing::Slice(1);
  // nc::indexing::Slice(0,1,std::monostate{});
  nc::indexing::Slice(1,0, None);
  vector<float> zz2 = {0.1,0.3,0.2,
                         1, 2 , 3,   //
                      -1.1,2.3,6.1,
                         4, 5 , 6,   //
                      0.9, 0.8,-0.5,
                        7, 8 ,  8 ,  //
                      -3, -2,-9,
                      10, 11, 12 };

  Tensor<float> v1 {zz2,{4,2,3}};
  cout<<"v1\n";
  v1.info();
  cout<<"----v1[2:4,1,:]---"<<endl;
  Tensor <float> out_v1 = v1.index({Slice(2,4),1,None});
  out_v1.info();
  cout<<"----v1[1:,1:, 0]"<<endl;
  vector<nc_Slice_Index> index_list = {Slice(1),Slice(1)};
  index_list.push_back(0);
  cout<<"nc_Slice_index vector:  ";
  print_nc_Slice_idx(index_list);
  cout<<endl;
  // for(int i=0; i<index_list.size(); i++){
  //   cout<<index_list[i]<<",";  
  // }
  // cout<<endl;
  
  out_v1 = v1.index(index_list); 
  out_v1.info();
  cout<<"----v1[2,:,1:]=put0---"<<endl;
  Tensor<float> put0 = arange<float>(0,4).reshape({1,2,2});
//   put0.info();
  v1.index_put({2,Slice(None),Slice(1)},put0);
  cout<<v1;
  cout<<"----v1[0:2,0,:]=1000---"<<endl;
  v1.index_put({Slice(0,2),0,None}, 1000);
  cout<<v1;
  cout<<"----indexing[2:4]:";
  cout<<nc::indexing::Slice(2,4)<<endl;
  cout<<"----indexing[:4]: ";
  cout<<nc::indexing::Slice(nc::indexing::None,4)<<endl;
  cout<<"----indexing[:]:  ";
  cout<<nc::indexing::Slice(nc::indexing::None,nc::indexing::None)<<endl;
}
void ex13(){
  cout<<"-----nc::tensor---"<<endl;
  vector<float> zz2 = {0.1,0.3,0.2,-1.1,2.3,6.1};
  Tensor<float> v1 {zz2,{2,3}};
  cout<<"v1\n";
  v1.info();
  cout<<"v1[0,0]:"<<v1.index({0,0})<<endl;
  vector<int> id0 = {0,1};
  cout<<"v1[0,1]:"<<v1.index(id0)<<endl;
  cout<<"----slice---"<<endl;
  Tensor<float> vout = v1.slice(/*dim*/1,1,2);
  vout.info();
  cout<<"----slice_put---"<<endl;
  vector<float> p_val_vec = {1,2,3,4}; 
  Tensor<float> p_val {p_val_vec,{2,2}};
  v1.slice_put(/*dim*/1,1,3, p_val);
  v1.info();
}

void ex14(){
  Tensor<float> t2 ({0.5,0.3,
                     0.1,-0.1}, {2,2});
  Tensor<float> t3 = arange<float> (0,4).reshape({2,2});
  cout<<"t2----"<<endl;
  t2.info();
  cout<<"t3----"<<endl;
  t3.info();
  cout<<"t4 = t2+t3------"<<endl;
  Tensor<float> t4 = t2.add(t3);
  /*t4
   0.5 1.3
   2.1 2.9
  */ 
  cout<<"t2 will not change----"<<endl;
  t2.info();
  cout<<"t4----"<<endl;
  t4.info();
  cout<<"t5 = -t4----"<<endl;
  Tensor<float> t5 = t4.minus();
  cout<<"t4 will not change---"<<endl;
  t4.info();
  cout<<"---t5---"<<endl;
  /*t5
  -0.5 -1.3
  -2.1 -2.9
  */
  t5.info();
  t5 = t4.minus(t5); 
  /*t4 = t4 - t4 
  1   2.6  
  4.2 5.8
  */
  t5.info();
  cout<<"----t5.minus(scalar=-1)  : t5-(-1) ---"<<endl;
  t5 = t5.minus(-1);  
  /*
  2   3.6
  5.2 6.8
  */
  t5.info();
}
void ex15(){
Tensor<float> t00 = arange<float>(0,6).reshape({2,-1});
  Tensor<float> t11 = arange<float>(-1,5).reshape({2,-1});
  cout<<"---t00---"<<endl;
  /* 0 1 2
     3 4 5*/
  t00.info();
  cout<<"---t11---"<<endl;
  /* -1 0 1 
      2 3 4*/
  t11.info();
  t00.mul(-1).info();
  t00.mul(t11).info();
  t00.add(10).info();
  // t11.div1(); //* err becuase t11 have 0 so 1/t11 will have err
  t00.add(10).div1().info();
  /*  t11/(t00+10)
  -1/10  0/11 1/12
   2/13  3/14 4/15
  */
  t11.div(t00.add(10)).info();
}
void ex16(){
  //* hstack only support 1D and 2D (because its weird to do hstack at 3d or 4d, concatentate makes more sense)  
  //todo implemnt concatenate, implement vstack
  cout<<"---hstack 2D----"<<endl;
  Tensor<float> t00 = arange<float>(0,6).reshape({2,-1});
  Tensor<float> t11 = arange<float>(-1,3).reshape({2,-1});
  Tensor<float> t22 = arange<float>(100,106).reshape({2,-1});
  Tensor<float> s2 = hstack({t00,t11,t22});
  s2.info();
  cout<<"---hstack 1D----"<<endl;
  t00 = arange<float>(0,3); 
  t11 = arange<float>(-1,3); 
  t22 = arange<float>(100,106);
  s2 = hstack({t00,t11,t22}); 
  //or vector<Tensor<float>> stack_tensors = {t00,t11,t22}
  // s2 =hstack(stack_tensors)
  cout<<"s2:"<<s2; //* cout is same as s2.info()
  cout<<"----vstack 2D----"<<endl; 
  t00 = arange<float>(0,6).reshape({2,3});
  t11 = arange<float>(-1,2).reshape({1,3});
  t22 = arange<float>(100,106).reshape({2,3});
  s2 = vstack({t00,t11,t22});
  cout<<s2;
  cout<<"----vstack 1D----"<<endl; 
  t00 = arange<float>(0,4);
  t11 = arange<float>(-1,3);
  t22 = arange<float>(100,104);
  s2 = vstack({t00,t11,t22});
  cout<<s2;
}
void ex17(){
  Tensor<float> t0 = arange<float>(100,106).reshape({2,-1});
  t0.index_put({0,1}, 200.0f);
  Tensor<float> t1 = max(t0, /*dim*/0);
  cout<<"t0---\n"<<t0;
  cout<<"max(t0,dim=0)---\n"<<t1;
  t1 = max(t0, /*dim*/1);
  cout<<"max(t0,dim=1)---\n"<<t1;
}