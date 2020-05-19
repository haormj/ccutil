package main

import (
	"fmt"

	"github.com/haormj/ccutil/module/goapi/vision"
)

func main() {
	dvc := vision.NewDogsVsCats()
	dvc.Load(
		"/mnt/project/github.com/haormj/vision/Project/DogsVsCats/dogs-vs-cats_vgg16.ths")

	urls := []string{
		"https://ss0.bdstatic.com/70cFuHSh_Q1YnxGkpoWK1HF6hhy/it/u=2211623652,2733906554&fm=26&gp=0.jpg",
	}

	for _, u := range urls {
		fmt.Println(dvc.PredictByUrl(u))
	}
}
