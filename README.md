# Cubo LED 8x8x8

![Estado](https://img.shields.io/badge/Estado-Completado-success)
![Arduino](https://img.shields.io/badge/Arduino-UNO-00979D?logo=arduino)
![Licencia](https://img.shields.io/badge/Licencia-MIT-blue)

Un cubo LED 8x8x8 completamente funcional controlado por Arduino UNO, utilizando registros de desplazamiento 74HC595 y multiplexación para crear impresionantes efectos visuales tridimensionales.

## Descripción del Proyecto

Este proyecto fue desarrollado para su presentación en un evento en Corposucre, en representación de la Universidad de Sucre. El objetivo fue demostrar las capacidades técnicas y creativas de los estudiantes en el área de sistemas embebidos y electrónica digital, mostrando un proyecto completo desde el diseño hasta la implementación física.

Este proyecto implementa un cubo LED de 8x8x8 (512 LEDs individuales) que permite crear animaciones y patrones tridimensionales. El sistema utiliza técnica de multiplexación por capas para controlar eficientemente los 512 LEDs con recursos limitados del microcontrolador.

El cubo fue desarrollado como proyecto educativo para demostrar conceptos de electrónica digital, control de periféricos mediante comunicación SPI, y programación en tiempo real con restricciones de hardware. La estructura física del cubo se construyó utilizando cable UTP como soporte rígido, garantizando precisión geométrica y durabilidad.

## Características

- **512 LEDs controlados individualmente** organizados en una matriz 3D de 8x8x8
- **Multiplexación eficiente** utilizando solo 8 pines GPIO del Arduino para controlar las capas
- **Comunicación SPI** de alta velocidad con 8 registros 74HC595 en cascada
- **Múltiples patrones programables:**
  - Encendido/apagado total sincronizado
  - Efecto de capas acumulativas ascendentes y descendentes
  - Animación de apagado progresivo por capas
  - Patrones personalizables mediante programación
- **Arquitectura modular** que permite agregar nuevos patrones fácilmente
- **Frecuencia de refresco optimizada** para evitar parpadeo visible (>60 Hz por capa)

## Componentes

| Componente | Cantidad | Descripción |
|------------|----------|-------------|
| Arduino UNO | 1 | Microcontrolador principal |
| 74HC595N | 8 | Registros de desplazamiento (control de columnas) |
| LEDs | 512 | Diodos emisores de luz (matriz 8×8×8) |
| Transistor 2N2222 | 8 | Transistores NPN (control de capas) |
| Resistencias 220Ω | 64 | Limitadoras de corriente |
| Cable UTP | ~3.5m | Estructura de soporte y conexiones |
| Flux | 1 | Facilitador de soldadura |
| Estaño | 1 rollo | Material de soldadura |
| Protoboard | 2+ | Para montaje de circuitos de control |
| Cables jumper | 50+ | Conexiones entre componentes |

## Esquemático

Los esquemáticos y diagramas detallados se encuentran en la carpeta [`/schematic`](/schematic):

- **`microcontrolador.jpg`** - Conexiones del Arduino UNO
- **`columnas.jpg`** - Distribución de los 8 registros 74HC595 para control de columnas
- **`filas.jpg`** - Sistema de control de capas con transistores 2N2222
- **`molde.jpg`** - Estructura física y dimensiones del cubo

### Conexiones Principales

**Arduino UNO → 74HC595:**
- Pin 11 (MOSI) → SER (pin 14 del primer registro)
- Pin 13 (SCK) → SRCLK (pin 11 de todos los registros)
- Pin 10 (SS) → RCLK (pin 12 de todos los registros)

**Arduino UNO → Transistores 2N2222:**
- Pines 2-9 → Base de transistores
- Colector de cada transistor → GND
- Emisor de cada transistor → Capa correspondiente del cubo

**74HC595N:**
- Pin 10 (SRCLR) → VCC (+5V)
- Pin 13 (OE) → GND
- Cascada: Q7' (pin 9) → SER (pin 14) del siguiente registro

## Funcionamiento

El cubo comenzará a ejecutar automáticamente los patrones programados en secuencia:

1. **Encendido total** - Todos los LEDs activos
2. **Capas acumulativas** - Las capas se encienden progresivamente de abajo hacia arriba
3. **Apagado progresivo** - Las capas se apagan secuencialmente
4. **Ciclo continuo** - Los patrones se repiten indefinidamente


## Troubleshooting

### Problema: No enciende ningún LED

**Causas posibles:**
- Verificar que pin 13 (OE) de los 74HC595 esté conectado a GND
- Confirmar que pin 10 (SRCLR) de los 74HC595 esté en VCC (+5V)
- Revisar conexiones SPI (pines 10, 11, 13 del Arduino)
- Verificar alimentación de 5V en todos los chips

### Problema: Se encienden todos los LEDs aleatoriamente

**Causas posibles:**
- SRCLR flotando o conectado incorrectamente
- Cascada de registros interrumpida (revisar Q7' → SER)
- RCLK no conectado correctamente

### Problema: Algunos LEDs no encienden

**Causas posibles:**
- Soldaduras frías - recalentar conexiones sospechosas
- LEDs con polaridad invertida
- Cables UTP con continuidad interrumpida
- Transistor de capa defectuoso

### Problema: Parpadeo excesivo

**Causas posibles:**
- Ajustar `delayMicroseconds()` en función `renderCube()`
- Aumentar frecuencia de multiplexación
- Reducir tiempo de pausa entre patrones

### Problema: Patrones no se ven correctos

**Causas posibles:**
- Verificar que no se use `delay()` dentro de las animaciones (usar `wait()` en su lugar)
- No activar capas manualmente con `digitalWrite()` - solo usar `renderCube()`
- Asegurar que `clearCube()` se llame antes de nuevos patrones

## Miembros

- **[Daniel I. Parra Baldovino]**
- **[Fabián J. Pastrana Pérez]**
- **[Yóbil J. Gómez Arrieta]**
- **[Juan M. Mercado Garrido]**

## 📄 Licencia

Este proyecto está bajo la Licencia MIT - ver el archivo [LICENSE](LICENSE) para más detalles.

---
