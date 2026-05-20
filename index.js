class Task {
    constructor(id, title, priority) {
        this.id = id;
        this.title = title;
        this.priority = priority;
        this.completed = false;
    }

    markCompleted() {
        this.completed = true;
    }

    display() {
        console.log(`ID: ${this.id}`);
        console.log(`Title: ${this.title}`);
        console.log(`Priority: ${this.priority}`);
        console.log(`Status: ${this.completed ? "Completed" : "Pending"}`);
        console.log("----------------------");
    }
}

class Expense {
    constructor(id, category, amount, note) {
        this.id = id;
        this.category = category;
        this.amount = amount;
        this.note = note;
        this.date = new Date().toLocaleDateString();
    }

    display() {
        console.log(`ID: ${this.id}`);
        console.log(`Category: ${this.category}`);
        console.log(`Amount: ₹${this.amount}`);
        console.log(`Note: ${this.note}`);
        console.log(`Date: ${this.date}`);
        console.log("----------------------");
    }
}

class PersonalManager {
    constructor() {
        this.tasks = [];
        this.expenses = [];
        this.taskId = 1;
        this.expenseId = 1;
    }

    addTask(title, priority) {
        const task = new Task(this.taskId++, title, priority);
        this.tasks.push(task);
        console.log("Task added successfully.");
    }

    viewTasks() {
        if (this.tasks.length === 0) {
            console.log("No tasks found.");
            return;
        }

        this.tasks.forEach(task => task.display());
    }

    completeTask(id) {
        const task = this.tasks.find(t => t.id === id);

        if (!task) {
            console.log("Task not found.");
            return;
        }

        task.markCompleted();
        console.log("Task marked as completed.");
    }

    deleteTask(id) {
        const index = this.tasks.findIndex(t => t.id === id);

        if (index === -1) {
            console.log("Task not found.");
            return;
        }

        this.tasks.splice(index, 1);
        console.log("Task deleted successfully.");
    }

    addExpense(category, amount, note) {
        if (amount <= 0) {
            console.log("Invalid amount.");
            return;
        }

        const expense = new Expense(this.expenseId++, category, amount, note);
        this.expenses.push(expense);
        console.log("Expense added successfully.");
    }

    viewExpenses() {
        if (this.expenses.length === 0) {
            console.log("No expenses found.");
            return;
        }

        this.expenses.forEach(expense => expense.display());
    }

    totalExpense() {
        const total = this.expenses.reduce((sum, expense) => sum + expense.amount, 0);
        console.log(`Total Expense: ₹${total}`);
    }

    categoryWiseExpense() {
        const result = {};

        for (let expense of this.expenses) {
            if (!result[expense.category]) {
                result[expense.category] = 0;
            }

            result[expense.category] += expense.amount;
        }

        console.log("Category Wise Expense:");
        for (let category in result) {
            console.log(`${category}: ₹${result[category]}`);
        }
    }

    showSummary() {
        const completed = this.tasks.filter(t => t.completed).length;
        const pending = this.tasks.length - completed;
        const totalExpense = this.expenses.reduce((sum, e) => sum + e.amount, 0);

        console.log("\n===== Summary =====");
        console.log(`Total Tasks: ${this.tasks.length}`);
        console.log(`Completed Tasks: ${completed}`);
        console.log(`Pending Tasks: ${pending}`);
        console.log(`Total Expenses: ₹${totalExpense}`);
    }
}

const manager = new PersonalManager();

manager.addTask("Complete Java assignment", "High");
manager.addTask("Revise DSA", "Medium");
manager.addTask("Push GitHub project", "High");

manager.viewTasks();

manager.completeTask(2);

manager.addExpense("Food", 250, "Lunch");
manager.addExpense("Travel", 120, "Metro");
manager.addExpense("Study", 500, "Course subscription");

manager.viewExpenses();
manager.totalExpense();
manager.categoryWiseExpense();
manager.showSummary();