# Windows Explorer Finder

這是一個整合 Windows 檔案總管的快速搜尋工具。透過右鍵選單，您可以快速在當前目錄開啟搜尋視窗，並將搜尋結果直接在原本的檔案總管視窗中選取 (Highlight)。

## 功能特色

*   **右鍵選單整合**：在檔案總管空白處右鍵點擊，即可看到「尋找檔案」選項。
*   **即時搜尋**：支援萬用字元（如 `*.cpp`）搜尋當前目錄下的檔案。
*   **雙向連動**：
    *   **單選**：點擊搜尋結果列表中的項目，檔案總管會自動捲動並選取該檔案。
    *   **全選**：點擊 "Select in Explorer" 按鈕，將所有搜尋結果在檔案總管中一次選取。
*   **現代化介面**：使用 Qt 6 開發的圖形使用者介面。

## 系統需求

*   Windows 10 / 11 (64-bit)
*   Visual Studio 2026 (用於編譯)
*   Qt 6.10.1 (MSVC 2022 64-bit)

## 專案結構

*   **ExplorerPlugin** (DLL): Windows Shell Extension，負責註冊右鍵選單並啟動主程式。
*   **ExplorerFinder** (EXE): Qt GUI 應用程式，負責搜尋邏輯與控制檔案總管行為。

## 編譯說明

1.  確保已安裝 Visual Studio 2026 與 Qt 6.10.1。
2.  開啟 `ExplorerFinder.slnx`。
3.  選擇 `Debug` 或 `Release` 設定，平台選擇 `x64`。
4.  建置方案 (Build Solution)。

## 安裝與使用

由於這是一個 Shell Extension，需要註冊 DLL 才能生效。

1.  **準備檔案**：
    確保 `ExplorerPlugin.dll` 與 `ExplorerFinder.exe` 位於**同一個資料夾**內。

2.  **註冊元件**：
    以**系統管理員身分**開啟命令提示字元 (CMD) 或 PowerShell，執行以下指令：
    ```powershell
    regsvr32 "你的路徑\ExplorerPlugin.dll"
    ```
    *成功後會跳出註冊成功的對話框。*

3.  **使用**：
    *   開啟任一檔案總管視窗。
    *   在資料夾空白處點擊**滑鼠右鍵**。
    *   選擇 **「尋找檔案」**。
    *   在彈出的視窗中輸入關鍵字並搜尋。

## 解除安裝

若要移除此工具，請先反註冊 DLL：

1.  以**系統管理員身分**開啟命令提示字元 (CMD) 或 PowerShell。
2.  執行以下指令：
    ```powershell
    regsvr32 /u "你的路徑\ExplorerPlugin.dll"
    ```
3.  刪除相關檔案即可。

## 注意事項

*   修改或重新編譯 DLL 時，可能需要重新啟動檔案總管 (`explorer.exe`) 或登出再登入，以釋放被佔用的 DLL 檔案。
*   搜尋預設支援萬用字元（例如輸入 `test` 會自動視為 `*test*`）。
