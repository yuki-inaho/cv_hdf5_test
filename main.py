import cv2
import os
import h5py
import numpy as np
import pdb

H5FILE_NAME = "lena.h5"

if os.path.exists(H5FILE_NAME):
    os.remove(H5FILE_NAME)

h5cv_write = cv2.hdf.open(H5FILE_NAME)
dir = '/image'
img = cv2.imread("./lena.png")

h5cv_write.grcreate(dir)
h5cv_write.dswrite(img, dir + "/lena")
h5cv_write.dswrite(np.array([[0.7]]), dir + "/lena_number")
h5cv_write.close()

h5cv = cv2.hdf.open(H5FILE_NAME)
if h5cv.hlexists("/image"):
    lena_img = h5cv.dsread("/image/lena")
    lena_number = h5cv.dsread("/image/lena_number")
h5cv.close()
