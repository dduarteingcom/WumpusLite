```md
#  WumpusLite — Clean Architecture Mini Project

## Overview
**WumpusLite** is a mini project inspired by the classic *Hunt the Wumpus* game, created as a **learning and portfolio-oriented exercise** to practice **Clean Architecture**, modularity, and separation of responsibilities in a concrete, non-trivial domain.

Rather than focusing on gameplay complexity, the project emphasizes **architectural clarity**, **explicit boundaries**, and **long-term maintainability**.

---

## Purpose
This project was built to explore a practical architectural question:

> *How can a system be structured so that core business rules remain stable while everything else can change?*

WumpusLite models a small but realistic domain to apply architectural principles deliberately, avoiding premature optimization or over-engineering.

---

## Architectural Principles Practiced

- **Clean Architecture**
  - Business rules at the center of the system
  - Dependencies always point inward
- **Modularity & Decoupling**
  - Changes in one part of the system do not cascade into others
- **Use Cases as Vertical Slices**
  - Application behavior organized by reasons for change, not by technical layers
- **Dependency Inversion**
  - High-level policies do not depend on low-level details
- **Explicit Architectural Boundaries**
  - Core domain logic isolated from interfaces and infrastructure

---

## Layered Structure (Conceptual)

- **Entities**
  - Core domain objects (`Player`, `Map`, `Event`)
  - Enforce invariants and contain no external dependencies
- **Use Cases**
  - Application-specific rules that coordinate entities and define system behavior
- **Interface Adapters**
  - Translate between domain concepts and external input/output
- **Frameworks & Drivers**
  - CLI interaction and application entry point

Each layer can evolve or be replaced independently without affecting the core domain.

---

## Scope and Constraints

- Command-line interface (CLI)
- In-memory state only
- No external libraries
- No persistence or networking

These constraints are intentional to keep the focus on **architecture and reasoning**, not tooling or infrastructure.

---

## What This Project Is Not

- Not a full game
- Not a framework
- Not a distributed or microservice-based system

The project deliberately avoids **premature architectural decisions**, reflecting lessons from *Clean Architecture* regarding over-engineering and unnecessary complexity.

---

## Key Takeaway

> **Good architecture preserves options.**  
> This project demonstrates how to delay irreversible decisions while still writing clean, testable, and extensible code.
```

