#include <iostream>

#include "haormj/vision.hpp"

int main() {
  haormj::vision::DogsVsCats dc;
  dc.init(
      "/mnt/project/github.com/haormj/vision/Project/DogsVsCats/"
      "dogs-vs-cats_vgg16.ths");
  std::vector<string> urls = {
      "https://ss0.bdstatic.com/70cFuHSh_Q1YnxGkpoWK1HF6hhy/it/"
      "u=2211623652,2733906554&fm=26&gp=0.jpg",
      "https://timgsa.baidu.com/"
      "timg?image&quality=80&size=b9999_10000&sec=1585189486763&di="
      "3c0b2a08137abe11cbdb7dc28e24afdb&imgtype=0&src=http%3A%2F%2Fimg1.imgtn."
      "bdimg.com%2Fit%2Fu%3D1976933516%2C341956374%26fm%3D214%26gp%3D0.jpg",
      "https://timgsa.baidu.com/"
      "timg?image&quality=80&size=b9999_10000&sec=1585189526185&di="
      "a1fb3d49c614c95199fb4eff953aa8a2&imgtype=0&src=http%3A%2F%2Fimg02."
      "tooopen.com%2FDowns%2Fimages%2F2010%2F7%2F30%2Fsy_20100730095430668065."
      "jpg",
      "https://ss2.bdstatic.com/70cFvnSh_Q1YnxGkpoWK1HF6hhy/it/"
      "u=3362414355,3460872153&fm=26&gp=0.jpg",
      "https://timgsa.baidu.com/"
      "timg?image&quality=80&size=b9999_10000&sec=1585189526185&di="
      "c23ef53e55aaf7693afa119d8d19dbf8&imgtype=0&src=http%3A%2F%2Fpic1."
      "win4000.com%2Fpic%2Fa%2F24%2F14f81301397.jpg",
      "https://timgsa.baidu.com/"
      "timg?image&quality=80&size=b9999_10000&sec=1585189526185&di="
      "7856c1410bcd4a92a6eb047428bc1606&imgtype=0&src=http%3A%2F%2Fdpic."
      "tiankong.com%2F1c%2Fwx%2FQJ6602846446.jpg",
      "https://ss3.bdstatic.com/70cFv8Sh_Q1YnxGkpoWK1HF6hhy/it/"
      "u=2364654808,1367649755&fm=26&gp=0.jpg",
      "https://timgsa.baidu.com/"
      "timg?image&quality=80&size=b9999_10000&sec=1585189664812&di="
      "2e8742a7c1479e392fd31ffd2a927c38&imgtype=0&src=http%3A%2F%2Fandroid-"
      "wallpapers.25pp.com%2Ffs04%2F2015%2F09%2F18%2F3%2F2000_"
      "1eb877cabf4cb4a22d4eca7f6fa0d04b_900x675.jpg",
      "https://timgsa.baidu.com/"
      "timg?image&quality=80&size=b9999_10000&sec=1585190048259&di="
      "68f2a3a6097a0c4ff34d687d241adba9&imgtype=0&src=http%3A%2F%2Fa4.att."
      "hudong.com%2F21%2F09%2F01200000026352136359091694357.jpg"};
  for (string s : urls) {
    std::cout << dc.predictByUrl(s) << std::endl;
  }
}
