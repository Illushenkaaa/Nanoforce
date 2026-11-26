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
   Commits made by the agent end with a `Co-Authored-By: Claude ...` trailer.
4. When the user asks to explain code: first give a short code example, then walk through that example step by step in plain, simple words.
5. Explanation style: short and to the point, the way the user talks.
   State the core rule in 1–3 plain sentences, confirm or correct the user's understanding directly,
   add one small example only if needed, and stop. No tables, sections or extra terms unless asked.

## Coding Rules

1. If a class must not be copied, inherit it from `NonCopyable` right away.
2. If nothing will inherit from a class, mark it `final` right away.
3. All constructors are `explicit`, for every class.
4. Use `[[nodiscard]]` wherever possible (getters, functions whose result must not be ignored),
   and other attributes (`[[noreturn]]`, `[[maybe_unused]]`, `[[likely]]`/`[[unlikely]]`, `[[fallthrough]]`) where they fit.

## Skills

`AI/Skills/` — agent skills used in this project.
