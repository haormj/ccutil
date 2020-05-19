
build:
	CGO_CXXFLAGS="-g -O2 -D_GLIBCXX_USE_CXX11_ABI=1 -I /usr/local/libtorch/include -I /usr/local/libtorch/include/torch/csrc/api/include -I /usr/local/include/opencv4" \
	CGO_LDFLAGS="-g -O2 -L/usr/local/libtorch/lib -lc10 -ltorch -lopencv_calib3d -lopencv_core -lopencv_dnn -lopencv_features2d -lopencv_flann -lopencv_gapi -lopencv_highgui -lopencv_imgcodecs -lopencv_imgproc -lopencv_ml -lopencv_objdetect -lopencv_photo -lopencv_stitching -lopencv_video -lopencv_videoio -lhaormj_vision -lhaormj_http -lcurl" \
	go build

run:
	LD_LIBRARY_PATH=.:$LD_LIBRARY_PATH:/usr/local/libtorch/lib:/usr/local/lib64 ./vision	
