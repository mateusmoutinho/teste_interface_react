#include <stdio.h>
#include "c2wasm.c"
#include "react.c"

// Handler for button clicks
c2wasm_js_var handleClick(c2wasm_js_var args) {
  c2wasm_call_object_prop(c2wasm_window, "alert", args);
  return c2wasm_null;
}

// Create a simple component
ReactComponent createAppComponent() {
  return ReactCreateElement(
    "div", 
    ReactCreateProps(
      "className", ReactCreateString("container"),
      "style", ReactCreateProps(
        "padding", ReactCreateString("20px"),
        "maxWidth", ReactCreateString("800px"),
        "margin", ReactCreateString("0 auto")
      )
    ),
    // Header
    ReactCreateElement("h1", 
      ReactCreateProps(
        "style", ReactCreateProps(
          "color", ReactCreateString("#333"),
          "borderBottom", ReactCreateString("2px solid #eee"),
          "paddingBottom", ReactCreateString("10px")
        )
      ), 
      ReactCreateString("Welcome to C-React")
    ),
    
    // Content
    ReactCreateFragment(
      ReactCreateElement("p", ReactNULL, 
        ReactCreateString("This page is rendered using React components written in C!")
      ),
      
      ReactCreateElement("p", ReactNULL, 
        ReactCreateString("WebAssembly enables C code to run directly in the browser with near-native performance.")
      ),
      
      ReactCreateElement(
        "button",
        ReactCreateProps(
          "onClick", ReactCreateClojure(
            handleClick,
            ReactCreateString("Hello from C-React!")
          ),
          "className", ReactCreateString("btn btn-primary"),
          "style", ReactCreateProps(
            "padding", ReactCreateString("10px 15px"),
            "backgroundColor", ReactCreateString("#0d6efd"),
            "color", ReactCreateString("white"),
            "border", ReactCreateString("none"),
            "borderRadius", ReactCreateString("4px"),
            "cursor", ReactCreateString("pointer"),
            "fontSize", ReactCreateString("16px"),
            "marginTop", ReactCreateString("15px")
          )
        ),
        ReactCreateString("Click Me")
      )
    )
  );
}

int main() {
  // Initialize React
  ReactStart();
  
  // Create our component
  ReactComponent app = createAppComponent();
  
  // Mount to DOM
  ReactRoot root = ReactDOMCreateRoot(ReactGetElementById("root"));
  ReactRootRender(root, app);
  
  return 0;
}