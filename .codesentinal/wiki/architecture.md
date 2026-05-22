# LLM Wiki Architecture

This document outlines the architecture of the LLM Wiki, designed to provide an AI Pull Request reviewer with the necessary context about the repository.

## Overview

The LLM Wiki leverages GitHub Actions to automate the generation, reading, and maintenance of repository knowledge. The core entrypoint for the system is `index.js`, which defines key classes and functionalities. The architecture is primarily driven by a set of GitHub Actions workflows that manage the wiki's content and integration with the GitHub platform.

## Major Modules and Entrypoints

*   **`index.js`**: This is the primary entrypoint for the application. It defines several core classes:
    *   `Expense`: Likely represents financial transactions.
    *   `manager`: A general manager or orchestrator class.
    *   `PersonalManager`: A specialized manager, possibly for personal finance or task management.
    *   `Task`: Represents actionable items or to-dos.

*   **Source Files**: The repository contains several source files written in different languages, indicating a multi-language project:
    *   `abc.java`: Contains the definition for a `Product` class, suggesting e-commerce or inventory related functionality.
    *   `helloworld.cpp`: Defines `Book` and `Library` classes, pointing towards a system for managing books.
    *   `main.py`: Defines `BankAccount` and `BankSystem` classes, indicating a banking or financial management system.

## Workflows

The following GitHub Actions workflows are central to the LLM Wiki's operation:

*   **`.github/workflows/contributor-codesentinal-contributor-wiki-update.yml`**: This workflow is part of the LLM Wiki system specifically designed for managing repository knowledge. It likely triggers updates or checks related to contributor-driven wiki content.

*   **`.github/workflows/mantainer-codesentinal-fork-review-only.yml`**: This workflow handles GitHub API integration, specifically tailored for reviewing pull requests originating from forks.

*   **`.github/workflows/mantainer-codesentinal-manual-wiki-update.yml`**: Another workflow for the LLM Wiki system, enabling manual updates to the repository's knowledge base.

*   **`.github/workflows/mantainer-codesentinal-same-repo-pr-all.yml`**: This workflow also focuses on GitHub API integration and appears to handle reviews for pull requests within the same repository, potentially covering all types of changes.

## Data Flow

The primary data flow is driven by changes within the repository and interactions through GitHub Pull Requests.

1.  **Code Changes**: Developers make changes to the source files (`.java`, `.cpp`, `.py`, `.js`).
2.  **Pull Request Creation**: A Pull Request is opened against the repository.
3.  **Workflow Triggering**: The GitHub Actions workflows (`mantainer-codesentinal-*`) are triggered based on the PR event and the configured workflow rules.
4.  **GitHub API Integration**: Workflows like `mantainer-codesentinal-fork-review-only.yml` and `mantainer-codesentinal-same-repo-pr-all.yml` likely interact with the GitHub API to fetch PR details, comment on PRs, or retrieve repository information.
5.  **Wiki Maintenance**: The `contributor-codesentinal-contributor-wiki-update.yml` and `mantainer-codesentinal-manual-wiki-update.yml` workflows are responsible for processing and potentially updating the wiki's knowledge base. This could involve analyzing code changes and generating documentation, or allowing manual edits to the wiki's content.
6.  **AI Reviewer Context**: The output of these workflows and the processed information from the repository are made available to the AI PR reviewer, likely through comments on the PR or a dedicated wiki interface.

## How This Architecture Guides PR Review

As an AI Pull Request reviewer, understanding this architecture helps in the following ways:

*   **Focus on Workflows**: Pay close attention to how the `mantainer-codesentinal-*` workflows are configured. Any changes to these workflows or their associated scripts directly impact how PRs are processed and reviewed.
*   **Entrypoint Significance**: Changes to `index.js` are critical as it's the main application entrypoint. Understand the classes defined within it (`Expense`, `manager`, `PersonalManager`, `Task`) and how they might interact with other parts of the system.
*   **Multi-Language Awareness**: Recognize that the repository is multi-lingual. PRs touching `abc.java`, `helloworld.cpp`, `main.py`, or `index.js` should be reviewed considering their respective language paradigms and the classes they define (`Product`, `Book`, `Library`, `BankAccount`, `BankSystem`, `Expense`, `Task`).
*   **Wiki Impact**: Evaluate changes that might affect the LLM Wiki's knowledge base. PRs that modify source files or logic relevant to documentation generation or maintenance should be scrutinized for their impact on the wiki's accuracy and completeness.
*   **GitHub Integration**: Be aware that PRs might trigger automated actions via GitHub Actions. Changes that could break GitHub API integrations or trigger unintended side effects in the CI/CD pipeline need careful consideration.
*   **Configuration Files**: While no external config files were detected beyond `.vscode` settings, be mindful of any such files that might emerge, as they often control core behavior. The `.vscode` files (`c_cpp_properties.json`, `launch.json`, `settings.json`) are primarily for developer tooling and are less likely to impact runtime architecture but can indicate development practices.

---

## CodeSentinal Wiki Update

**Reason:** The `main.py` file has been refactored to manage inventory instead of students, and the naming of classes and functions has been updated accordingly. The wiki should reflect these changes to provide accurate architectural context.

## Project Refactoring: From Student Management to Inventory Management

The `main.py` file has undergone a significant refactoring, shifting its focus from managing student data to managing inventory (products). This involves renaming the `BankAccount` and `BankSystem` classes to `Product` and `InventoryManager`, respectively, and updating all methods and attributes to reflect this new domain. Consequently, the old menu options related to student management have been replaced with new options for inventory management (e.g., Add Product, View Products, Update Quantity, Delete Product, Sort Products, Show Total Inventory Value).
