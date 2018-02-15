index.html: main.cc splash.h constants.h map.h mobAI.h startup.h html_template/index_template.html app.css game.js
	emcc -o index.html main.cc -O3 -std=c++11 -s WASM=1 --shell-file html_template/index_template.html -s NO_EXIT_RUNTIME=1  -s EXTRA_EXPORTED_RUNTIME_METHODS='["ccall"]'
clean:
	rm index.js index.wasm index.html
