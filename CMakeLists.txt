set(srcs
    "src/snv_panel_1306.c"
    "src/snv_graphics_lib.c"
)

set(includes
    "include"
)

set(priv_requires
    "esp_lcd"
)

idf_component_register(
    SRCS ${srcs}
    INCLUDE_DIRS ${includes}
    PRIV_REQUIRES ${priv_requires}
)