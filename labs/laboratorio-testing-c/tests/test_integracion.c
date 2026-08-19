#include <stdio.h>
#include "../src/carrito.h"
#include "minunit/minunit.h"

/*
 * Tests de integracion: verifican que las funciones trabajan bien
 * en combinacion, no de forma aislada.
 */

/* ═══════════════════════════════════════════════════════════════════════════
 *  PARTE D — Escribir el test guiado (ver README.md, Parte 8)
 * ═══════════════════════════════════════════════════════════════════════════ */

/* TODO: escribir test_compra_con_descuento() siguiendo la guia del .md */

void test_compra_con_descuento(void) {
    Carrito c;
    Producto pan = {"Pan", 200, 3};
    Producto leche = {"Leche", 350, 2};

    carrito_init(&c);
    carrito_agregar(&c, pan);
    carrito_agregar(&c, leche);

    int total = carrito_total(&c);
    int total_con_descuento = carrito_descuento(total, 10);

    ASSERT_IGUAL(total, 1300);
    ASSERT_IGUAL(total_con_descuento, 1170);
}

/* ═══════════════════════════════════════════════════════════════════════════
 *  PARTE E — Disenar un test propio (ver README.md, Parte 9)
 * ═══════════════════════════════════════════════════════════════════════════ */

/* TODO: escribir test_agregar_hasta_llenar() */

void test_agregar_hasta_llenar(void) {
    Carrito c;
    Producto p = {"Producto", 100, 1};

    carrito_init(&c);

    for (int i = 0; i < MAX_ITEMS; i++) {
        carrito_agregar(&c, p);
    }

    ASSERT_IGUAL(carrito_contar(&c), MAX_ITEMS);
    ASSERT_IGUAL(carrito_agregar(&c, p), 0);
    ASSERT_IGUAL(carrito_contar(&c), MAX_ITEMS);
}

int main(void) {
    printf("=== Tests de integracion ===");
    /* Descomentar a medida que agregues las funciones: */
    test_compra_con_descuento();
    test_agregar_hasta_llenar(); 
    RESUMEN();
    return EXIT_CODE();
}
