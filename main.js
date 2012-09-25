function handleFiles(files, id) {
	// we only handle a single file
	var file = files[0];
	
	var imageType =/image.*/;
	if (!file.type.match(imageType)) {
		return false;
	}

	var img = document.createElement("img");
	var dataURLReader = new FileReader();
	dataURLReader.onloadend = function() {
		img.src = dataURLReader.result;
		/* after we load the image draw it into a canvas so we can get the pixel data */
		img.onload = function () {
			var canvas = document.getElementById("canvas" + id);
			canvas.width = img.width;
			canvas.height = img.height;
			ctx = canvas.getContext('2d');
			ctx.drawImage(img, 0, 0);
		};
	}
	dataURLReader.readAsDataURL(file);
	
	return true;
}

