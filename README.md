# Dynamic

A Geode mod prototype for Geometry Dash 2.2081 that adds a timing-window concept around a selected jump.

Features:
- master enable/disable
- 7-key menu hotkey
- activation-point list
- early and late tolerance controls
- debug label
- modular logic and UI design

This is intentionally conservative:
- no global physics edits
- no speed changes
- no broad jump rewrites
- late clicks are only allowed when the real GD state still makes the jump valid

Build setup:
1. Install Geode and Geometry Dash 2.2081
2. Clone the Geode SDK
3. Put this project in a folder
4. Set GEODE_SDK_PATH to your SDK folder
5. Build:
   cmake -B build -S . -DGEODE_SDK_PATH=/path/to/geode-sdk
   cmake --build build --config Release
6. Copy the generated .geode file into your Geode mods folder
7. Start GD and press 7

Note:
This project is a prototype scaffold. To make it gameplay-safe for real jump timing, you still need to patch the exact GD 2.2081 player input and collision validation path.