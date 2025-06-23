# 🕵️ Arduino #15: Hareket Sensörü (PIR) ile LED Kontrolü

Bu projede, bir **PIR hareket sensörü** kullanarak ortamda hareket algılandığında **iki farklı LED’i kontrol eden bir sistem** oluşturacağız.  
→ **Hareket varsa**: Kırmızı LED yanar  
→ **Hareket yoksa**: Yeşil LED yanar

🔗 [Web Siteme Bakmak İçin Tıkla](https://www.hakkiharmankaya.com/)  
🔗 [Tinkercad Tasarımına Göz At](https://www.tinkercad.com/things/7W7i56JReKT?sharecode=h5l6fQGt7gKbcTZJKzp9HeLspzn0cP_qewfo_Rvxsec)

---

## 🧰 Gerekli Malzemeler

- 1 adet **PIR sensörü**
- 1 adet **Arduino**
- 2 adet **LED** (kırmızı ve yeşil)
- 2 adet **direnç** (220Ω veya 330Ω)
- **Jumper kabloları**

---

## ⚙️ Adım Adım Devre Kurulumu

### 🔹 Adım 1: Devreyi Kurun

**PIR Sensörü**:
- **VCC** → **5V**
- **GND** → **GND**
- **OUT** → **D4**

**LED Bağlantıları**:
- **Kırmızı LED**:
  - **Anot (uzun bacak)** → direnç → **D3**
  - **Katot (kısa bacak)** → **GND**

- **Yeşil LED**:
  - **Anot** → direnç → **D2**
  - **Katot** → **GND**

> 🔧 Sensörün üzerinde iki potansiyometre (ayar düğmesi) bulunur:
> - Sol: **Zaman ayarı** (3 saniye – 5 dakika)
> - Sağ: **Mesafe ayarı** (3 – 7 metre)

---

## 🔹 Adım 2: Arduino Kodunu Yazın ve Yükleyin

```cpp
int hpin = 4; // PIR sensör pin
int kpin = 3; // Kırmızı LED pin
int ypin = 2; // Yeşil LED pin
int hareket;

void setup() {
  pinMode(hpin, INPUT);
  pinMode(kpin, OUTPUT);
  pinMode(ypin, OUTPUT);
}

void loop() {
  hareket = digitalRead(hpin);

  if (hareket == 1) {
    digitalWrite(kpin, HIGH); // Kırmızı yanar
    digitalWrite(ypin, LOW);  // Yeşil söner
  } else {
    digitalWrite(kpin, LOW);  // Kırmızı söner
    digitalWrite(ypin, HIGH); // Yeşil yanar
  }
}
