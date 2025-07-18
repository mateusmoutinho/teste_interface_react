#include <stdio.h>
#include <string.h>
#include "c2wasm.c"
#include "react.c"

// Global state for storing processes
c2wasm_js_var processes_array = c2wasm_null;

// Handler for adding new processes
c2wasm_js_var handleAddProcess(c2wasm_js_var args) {
    // Get input values from the form
    c2wasm_js_var processNumInput = ReactGetElementById("process-number-input");
    c2wasm_js_var creditorsInput = ReactGetElementById("creditors-input");
    
    // Create new process object
    c2wasm_js_var newProcess = c2wasm_create_object();
    c2wasm_set_object_prop_string(newProcess, "number", "000.000.000.000"); // Placeholder
    c2wasm_set_object_prop_string(newProcess, "creditors", "New Creditor");
    c2wasm_set_object_prop_string(newProcess, "status", "Não Adicionado");
    
    // Add to processes array
    c2wasm_append_array_any(processes_array, newProcess);
    
    c2wasm_js_var alert_args = c2wasm_create_array();
    c2wasm_append_array_string(alert_args, "Processo adicionado com suscesso");
    c2wasm_call_object_prop(c2wasm_window, "alert", alert_args);
    return c2wasm_null;
}

// Handler for clearing form
c2wasm_js_var handleClear(c2wasm_js_var args) {
    // Clear the input fields
    return c2wasm_null;
}

// Handler for saving processes
c2wasm_js_var handleSaveProcesses(c2wasm_js_var args) {

    c2wasm_js_var alert_args = c2wasm_create_array();
    c2wasm_append_array_string(alert_args, "Processos salvos!");
    c2wasm_call_object_prop(c2wasm_window, "alert", alert_args);
    return c2wasm_null;
}

// Create header component
ReactComponent createHeader() {
    return ReactCreateElement(
        "div",
        ReactCreateProps(
            "style", ReactCreateProps(
                "backgroundColor", ReactCreateString("#36c5f0"),
                "color", ReactCreateString("white"),
                "padding", ReactCreateString("20px"),
                "display", ReactCreateString("flex"),
                "justifyContent", ReactCreateString("space-between"),
                "alignItems", ReactCreateString("center")
            )
        ),
        ReactCreateFragment(
            ReactCreateElement("span", 
                ReactCreateProps("style", ReactCreateProps("cursor", ReactCreateString("pointer"))),
                ReactCreateString("← Voltar")
            ),
            ReactCreateElement("div", NULL,
                ReactCreateFragment(
                    ReactCreateElement("span", NULL, ReactCreateString("Olá Samuel ")),
                    ReactCreateElement("span", 
                        ReactCreateProps("style", ReactCreateProps(
                            "backgroundColor", ReactCreateString("white"),
                            "color", ReactCreateString("#36c5f0"),
                            "borderRadius", ReactCreateString("50%"),
                            "padding", ReactCreateString("5px 10px"),
                            "marginLeft", ReactCreateString("10px")
                        )),
                        ReactCreateString("OS")
                    )
                )
            )
        )
    );
}

// Create navigation tabs
ReactComponent createNavTabs() {
    return ReactCreateElement(
        "div",
        ReactCreateProps(
            "style", ReactCreateProps(
                "backgroundColor", ReactCreateString("#36c5f0"),
                "padding", ReactCreateString("0 20px"),
                "display", ReactCreateString("flex"),
                "gap", ReactCreateString("30px")
            )
        ),
        ReactCreateFragment(
            ReactCreateElement("span", 
                ReactCreateProps("style", ReactCreateProps(
                    "padding", ReactCreateString("10px 0"),
                    "cursor", ReactCreateString("pointer")
                )),
                ReactCreateString("Dashboard")
            ),
            ReactCreateElement("span", 
                ReactCreateProps("style", ReactCreateProps(
                    "padding", ReactCreateString("10px 0"),
                    "cursor", ReactCreateString("pointer"),
                    "borderBottom", ReactCreateString("2px solid white")
                )),
                ReactCreateString("Processos")
            ),
            ReactCreateElement("span", 
                ReactCreateProps("style", ReactCreateProps(
                    "padding", ReactCreateString("10px 0"),
                    "cursor", ReactCreateString("pointer")
                )),
                ReactCreateString("Usuário")
            )
        )
    );
}

// Create add process form
ReactComponent createAddProcessForm() {
    return ReactCreateElement(
        "div",
        ReactCreateProps(
            "style", ReactCreateProps(
                "backgroundColor", ReactCreateString("white"),
                "borderRadius", ReactCreateString("10px"),
                "padding", ReactCreateString("30px"),
                "margin", ReactCreateString("20px"),
                "boxShadow", ReactCreateString("0 2px 4px rgba(0,0,0,0.1)")
            )
        ),
        ReactCreateFragment(
            ReactCreateElement("h2", 
                ReactCreateProps("style", ReactCreateProps(
                    "marginBottom", ReactCreateString("20px"),
                    "color", ReactCreateString("#333")
                )),
                ReactCreateString("Adicionar Processos")
            ),
            ReactCreateElement("div", 
                ReactCreateProps("style", ReactCreateProps(
                    "display", ReactCreateString("grid"),
                    "gridTemplateColumns", ReactCreateString("1fr 1fr"),
                    "gap", ReactCreateString("20px"),
                    "marginBottom", ReactCreateString("20px")
                )),
                ReactCreateFragment(
                    ReactCreateElement("div", ReactNULL,
                        ReactCreateFragment(
                            ReactCreateElement("label", 
                                ReactCreateProps("style", ReactCreateProps(
                                    "display", ReactCreateString("block"),
                                    "marginBottom", ReactCreateString("5px"),
                                    "color", ReactCreateString("#666")
                                )),
                                ReactCreateString("Número do processos")
                            ),
                            ReactCreateElement("textarea", 
                                ReactCreateProps(
                                    "id", ReactCreateString("process-number-input"),
                                    "defaultValue", ReactCreateString(""),
                                    "style", ReactCreateProps(
                                        "width", ReactCreateString("100%"),
                                        "height", ReactCreateString("150px"),
                                        "border", ReactCreateString("1px solid #ddd"),
                                        "borderRadius", ReactCreateString("4px"),
                                        "padding", ReactCreateString("10px"),
                                        "resize", ReactCreateString("none")
                                    )
                                ),
                                ReactNULL
                            )
                        )
                    ),
                    ReactCreateElement("div", ReactNULL,
                        ReactCreateFragment(
                            ReactCreateElement("label", 
                                ReactCreateProps("style", ReactCreateProps(
                                    "display", ReactCreateString("block"),
                                    "marginBottom", ReactCreateString("5px"),
                                    "color", ReactCreateString("#666")
                                )),
                                ReactCreateString("Credores")
                            ),
                            ReactCreateElement("textarea", 
                                ReactCreateProps(
                                    "id", ReactCreateString("creditors-input"),
                                    "defaultValue", ReactCreateString(""),
                                    "style", ReactCreateProps(
                                        "width", ReactCreateString("100%"),
                                        "height", ReactCreateString("150px"),
                                        "border", ReactCreateString("1px solid #ddd"),
                                        "borderRadius", ReactCreateString("4px"),
                                        "padding", ReactCreateString("10px"),
                                        "resize", ReactCreateString("none")
                                    )
                                ),
                                ReactNULL
                            )
                        )
                    )
                )
            ),
            ReactCreateElement("div", 
                ReactCreateProps("style", ReactCreateProps(
                    "display", ReactCreateString("flex"),
                    "justifyContent", ReactCreateString("flex-end"),
                    "gap", ReactCreateString("10px")
                )),
                ReactCreateFragment(
                    ReactCreateElement("button",
                        ReactCreateProps(
                            "onClick", ReactCreateClojure(handleClear, ReactCreateString("clear")),
                            "style", ReactCreateProps(
                                "padding", ReactCreateString("10px 30px"),
                                "backgroundColor", ReactCreateString("#ff6b35"),
                                "color", ReactCreateString("white"),
                                "border", ReactCreateString("none"),
                                "borderRadius", ReactCreateString("4px"),
                                "cursor", ReactCreateString("pointer"),
                                "fontSize", ReactCreateString("16px")
                            )
                        ),
                        ReactCreateString("Limpar")
                    ),
                    ReactCreateElement("button",
                        ReactCreateProps(
                            "onClick", ReactCreateClojure(handleSaveProcesses, ReactCreateString("save")),
                            "style", ReactCreateProps(
                                "padding", ReactCreateString("10px 30px"),
                                "backgroundColor", ReactCreateString("#5eb8b4"),
                                "color", ReactCreateString("white"),
                                "border", ReactCreateString("none"),
                                "borderRadius", ReactCreateString("4px"),
                                "cursor", ReactCreateString("pointer"),
                                "fontSize", ReactCreateString("16px")
                            )
                        ),
                        ReactCreateString("Salvar Processos")
                    )
                )
            )
        )
    );
}

// Create process row component
ReactComponent createProcessRow(const char* number, const char* creditors, const char* status) {
    const char* statusColor = "#5eb8b4"; // Default green
    if (strcmp(status, "Não Adicionado") == 0) {
        statusColor = "#ff6b35"; // Orange/red for not added
    }
    
    return ReactCreateElement(
        "tr",
        ReactCreateProps("style", ReactCreateProps(
            "borderBottom", ReactCreateString("1px solid #eee")
        )),
        ReactCreateFragment(
            ReactCreateElement("td", 
                ReactCreateProps("style", ReactCreateProps(
                    "padding", ReactCreateString("15px"),
                    "textAlign", ReactCreateString("center")
                )),
                ReactCreateString(number)
            ),
            ReactCreateElement("td", 
                ReactCreateProps("style", ReactCreateProps(
                    "padding", ReactCreateString("15px"),
                    "textAlign", ReactCreateString("center")
                )),
                ReactCreateString(creditors)
            ),
            ReactCreateElement("td", 
                ReactCreateProps("style", ReactCreateProps(
                    "padding", ReactCreateString("15px"),
                    "textAlign", ReactCreateString("center"),
                    "color", ReactCreateString(statusColor),
                    "fontWeight", ReactCreateString("500")
                )),
                ReactCreateFragment(
                    ReactCreateString(status),
                    ReactCreateString(" "),
                    ReactCreateElement("span", ReactNULL, 
                        ReactCreateString(strcmp(status, "Adicionado") == 0 ? "✓" : "✗")
                    )
                )
            )
        )
    );
}

// Create process list component
ReactComponent createProcessList() {
    return ReactCreateElement(
        "div",
        ReactCreateProps(
            "style", ReactCreateProps(
                "backgroundColor", ReactCreateString("white"),
                "borderRadius", ReactCreateString("10px"),
                "padding", ReactCreateString("30px"),
                "margin", ReactCreateString("20px"),
                "boxShadow", ReactCreateString("0 2px 4px rgba(0,0,0,0.1)")
            )
        ),
        ReactCreateFragment(
            ReactCreateElement("h2", 
                ReactCreateProps("style", ReactCreateProps(
                    "marginBottom", ReactCreateString("20px"),
                    "color", ReactCreateString("#333")
                )),
                ReactCreateString("Processos e Status")
            ),
            ReactCreateElement("div", 
                ReactCreateProps("style", ReactCreateProps(
                    "marginBottom", ReactCreateString("20px")
                )),
                ReactCreateFragment(
                    ReactCreateElement("p", 
                        ReactCreateProps("style", ReactCreateProps(
                            "marginBottom", ReactCreateString("10px"),
                            "color", ReactCreateString("#666")
                        )),
                        ReactCreateString("Filtrar por:")
                    ),
                    ReactCreateElement("div", 
                        ReactCreateProps("style", ReactCreateProps(
                            "display", ReactCreateString("flex"),
                            "gap", ReactCreateString("10px"),
                            "alignItems", ReactCreateString("center")
                        )),
                        ReactCreateFragment(
                            ReactCreateElement("input", 
                                ReactCreateProps(
                                    "type", ReactCreateString("text"),
                                    "placeholder", ReactCreateString("Número do processo ou nome dos credores"),
                                    "style", ReactCreateProps(
                                        "flex", ReactCreateString("1"),
                                        "padding", ReactCreateString("8px"),
                                        "border", ReactCreateString("1px solid #ddd"),
                                        "borderRadius", ReactCreateString("4px")
                                    )
                                ),
                                ReactNULL
                            ),
                            ReactCreateElement("select", 
                                ReactCreateProps(
                                    "style", ReactCreateProps(
                                        "padding", ReactCreateString("8px"),
                                        "border", ReactCreateString("1px solid #ddd"),
                                        "borderRadius", ReactCreateString("4px"),
                                        "minWidth", ReactCreateString("150px")
                                    )
                                ),
                                ReactCreateElement("option", ReactNULL, ReactCreateString("Status"))
                            ),
                            ReactCreateElement("button",
                                ReactCreateProps(
                                    "style", ReactCreateProps(
                                        "padding", ReactCreateString("8px 20px"),
                                        "backgroundColor", ReactCreateString("white"),
                                        "border", ReactCreateString("1px solid #ddd"),
                                        "borderRadius", ReactCreateString("4px"),
                                        "cursor", ReactCreateString("pointer")
                                    )
                                ),
                                ReactCreateString("Filtrar")
                            )
                        )
                    )
                )
            ),
            ReactCreateElement("table", 
                ReactCreateProps("style", ReactCreateProps(
                    "width", ReactCreateString("100%"),
                    "borderCollapse", ReactCreateString("collapse")
                )),
                ReactCreateFragment(
                    ReactCreateElement("thead", ReactNULL,
                        ReactCreateElement("tr", 
                            ReactCreateProps("style", ReactCreateProps(
                                "backgroundColor", ReactCreateString("#4a4a4a"),
                                "color", ReactCreateString("white")
                            )),
                            ReactCreateFragment(
                                ReactCreateElement("th", 
                                    ReactCreateProps("style", ReactCreateProps(
                                        "padding", ReactCreateString("15px"),
                                        "textAlign", ReactCreateString("center")
                                    )),
                                    ReactCreateString("Número do Processo")
                                ),
                                ReactCreateElement("th", 
                                    ReactCreateProps("style", ReactCreateProps(
                                        "padding", ReactCreateString("15px"),
                                        "textAlign", ReactCreateString("center")
                                    )),
                                    ReactCreateString("Credores")
                                ),
                                ReactCreateElement("th", 
                                    ReactCreateProps("style", ReactCreateProps(
                                        "padding", ReactCreateString("15px"),
                                        "textAlign", ReactCreateString("center")
                                    )),
                                    ReactCreateString("Status")
                                )
                            )
                        )
                    ),
                    ReactCreateElement("tbody", ReactNULL,
                        ReactCreateFragment(
                            createProcessRow("000.000.000.000", "Empresa X", "Adicionado"),
                            createProcessRow("000.000.000.000", "João Silva, Maria Oliveira", "Adicionado"),
                            createProcessRow("Lista I", "Fulano da Silva", "Não Adicionado"),
                            createProcessRow("000.000.000.000", "Banco ABC, Financeira XPTO", "Adicionado"),
                            createProcessRow("123 João Lima", "-", "Não Adicionado"),
                            createProcessRow("000.000.000.000", "-", "Adicionado"),
                            createProcessRow("000.000.000.000", "Empresa Y, Empresa Z", "Adicionado"),
                            createProcessRow("1", "-", "Não Adicionado")
                        )
                    )
                )
            )
        )
    );
}

// Create main app component
ReactComponent createAppComponent() {
    return ReactCreateElement(
        "div", 
        ReactCreateProps(
            "style", ReactCreateProps(
                "backgroundColor", ReactCreateString("#f5f5f5"),
                "minHeight", ReactCreateString("100vh"),
                "fontFamily", ReactCreateString("Arial, sans-serif")
            )
        ),
        ReactCreateFragment(
            createHeader(),
            createNavTabs(),
            createAddProcessForm(),
            createProcessList()
        )
    );
}

int main() {
    // Initialize React
    ReactStart();
    
    // Initialize processes array
    processes_array = c2wasm_create_array();
    
    // Create our component
    ReactComponent app = createAppComponent();
    
    // Mount to DOM
    ReactRoot root = ReactDOMCreateRoot(ReactGetElementById("root"));
    ReactRootRender(root, app);
    
    return 0;
}