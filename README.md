---
slideOptions:
  spotlight:
    enabled: false
---
{%hackmd @navibluer/darkTheme %}


# System Programing
### SIC Two-Pass

---

### 專案說明

- 使用語言： C++ 11

- 執行方式：

    `./TwoPass < testSIC.txt`

- 輸出執行結果至檔案：

    `./TwoPass < testSIC.txt > obj_program.txt`

----

### 專案架構
![](https://i.imgur.com/UZnPc8W.png)

- 測試資料：`testSIC.txt`

- 主程式：`TwoPass.cpp`

- 中間檔：`middle.txt`

- 執行結果：`obj_program.txt`

----

#### 主程式

![](https://i.imgur.com/xtVSWxa.png)

----

### 其他檔案

- `compile.h`：

    讀取測資、以空格, Tab, \n, \r 做 Split

- `opTable.h`：

    建立 Opcode Table 以及查詢

- `errTable.h`：

    建立 Error Message 以及查詢


----

### Pass One

![](https://i.imgur.com/KhYoVp3.png)

----

#### 中間檔格式

![](https://i.imgur.com/evx1vDr.png)

----

### Pass Two
![](https://i.imgur.com/aRrfixo.png)

---

### 正確 Case

- #### RSUB 可以有 Label 
    ![](https://i.imgur.com/YVgJDco.png)
    
- #### 索引定址前後可以空白
    ![](https://i.imgur.com/0X5822O.png)
    
    ![](https://i.imgur.com/xU7Puwj.png)

----

- #### 程式碼可以改起始位置 

    Start From 1000
    
    ![](https://i.imgur.com/ju6hDed.png)
    
    Start From 4000
    
    ![](https://i.imgur.com/kEC53Bi.png)

----

- #### BYTE型態與內容之間可以空白
    ![](https://i.imgur.com/ruKgLKo.png)
    
    ![](https://i.imgur.com/xjt2qMu.png)
    
- #### BYTE 內容可以無限
    ![](https://i.imgur.com/OGgoiZl.png)

- #### 程式名需補空白到6碼 
    ![](https://i.imgur.com/QpGbCbA.png)

---

### 錯誤 Case

- #### 多個錯誤訊息
    ![](https://i.imgur.com/OYQl7lc.png)

----

### Syntax Error
1. 程式碼無法化成三欄式

    ![](https://i.imgur.com/RIqH90S.png)
    ![](https://i.imgur.com/MEcSsVS.png)

----

### Operand Error
1. START 位置錯誤

    ![](https://i.imgur.com/zTiY69B.png)
    ![](https://i.imgur.com/Js6uofw.png)

2. RESB, RESW, WORD 只能接十進位數字

    ![](https://i.imgur.com/0hvtOdI.png)
    ![](https://i.imgur.com/MWvOGbr.png)

----

3. BYTE 格式錯誤

    ![](https://i.imgur.com/W73iVNN.png)

    ![](https://i.imgur.com/KmhBDdY.png)

4. RSUB 不能有 Operand

    ![](https://i.imgur.com/NNLaD4w.png)

5. 其他都要有 Operand

    ![](https://i.imgur.com/fjM9fy2.png)

6. 索引定址格式錯誤

    ![](https://i.imgur.com/sfevZT5.png)

----

### Mnemoic Error
1. Opcode 錯誤 

    ![](https://i.imgur.com/azGW981.png)

----

### Label Error
1. Label 不能和 Operand 相同

    ![](https://i.imgur.com/6ZT6bDB.png)

----

1. START, END

    ![](https://i.imgur.com/71iAADg.png)

----

### Symbol Error
1. 無法找到 Symbol

    ![](https://i.imgur.com/hexyD0D.png)
    ![](https://i.imgur.com/c42Rtoj.png)

1. 重覆定義 Symbol

    ![](https://i.imgur.com/p9w9CDR.png)

---

# END

<style>
    .reveal img {
        max-height: 650px;
        margin: 0;
    }
    
    .reveal h3 {
        font-size: 48px;
    }
    
    .reveal h4 {
        font-size: 36px;
    }
    
    .reveal {
        font-size: 32px;
    }
</style>