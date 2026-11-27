# Nanoforce

A game engine written from scratch. C++23, CMake, Conan, MSVC.

## Goal

Get hands-on with the graphics APIs: Vulkan, DirectX, OpenGL.
Long term: maybe a Nanite-like renderer, or simply a convenient playground for experimenting with new technologies.

## Common Rules

1. Before doing anything, explain the full plan (short and to the point, no filler) and wait for the user's answer.
   Proceed without waiting only when the user explicitly says so.
2. No tests: we do not write tests in this project.
3. Commit messages: as short as possible, a single line, e.g. `Add log`.
   Commits made by the agent end with agents name trailer.
4. When the user asks to explain code: first give a short code example, then walk through that example step by step in plain, simple words. 
   Be ready to create a note for obsidian.
5. Explanation style: short and to the point, the way the user talks.
   State the core rule in 1–3 plain sentences, confirm or correct the user's understanding directly,
   add one small example only if needed, and stop. No tables, sections or extra terms unless asked.

## Coding Rules

1. If a class must not be copied, inherit it from `NonCopyable` right away.
2. If nothing will inherit from a class, mark it `final` right away.
3. All constructors are `explicit`, for every class.
4. Use `[[nodiscard]]` wherever possible (getters, functions whose result must not be ignored),
   and other attributes (`[[noreturn]]`, `[[maybe_unused]]`, `[[likely]]`/`[[unlikely]]`, `[[fallthrough]]`) where they fit.
5. Use `auto` widely: for local variables, iterators, lambdas and wherever the type is obvious from the right side.
6. Own resources with smart pointers: `std::unique_ptr` by default, `std::shared_ptr` only when ownership is really shared.
   No raw `new`/`delete`; raw pointers only as non-owning references.
7. Split function bodies into sections with short comments: `// create main window ->`, `// finalize ->`.
8. Lambdas passed as arguments: break after the previous argument and after the lambda signature with a trailing `//`,
   so the body stays on its own lines:
   ```cpp
   glfwSetKeyCallback(m_window,                   //
       [](GLFWwindow* window, int key, ...)       //
       {
           ...
       });
   ```
9. Managers are created by the class that owns them (in its constructor), not passed in from outside.
10. Don't repeat code (DRY): move repeated blocks into a separate function or method.

## Obsidian Notes

Vault by default: `C:\Users\user\Documents\Obsidian`, one topic per note, grouped in subfolders (e.g. `C++\Concepts.md`).

1. Write a note only after the user confirms they understood the topic.
2. Notes are written in English.
3. Structure: `## Theory` first — each definition stated once, as short bullets;
   then `## Code` — examples only, no repeated definitions, no step-by-step walkthroughs.
4. The user edits notes by hand: always read a note before changing it and keep their edits.

## Skills

`AI/Skills/` — agent skills used in this project.
