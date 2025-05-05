document.addEventListener('DOMContentLoaded', function() {
    // Function to show a specific section and hide others
    function showSection(sectionId) {
        const sections = document.querySelectorAll('.login-container');
        sections.forEach(section => {
            if (section.id === sectionId) {
                section.classList.add('visible');
            } else {
                section.classList.remove('visible');
            }
        });

        // If showing the welcome section, update the username
        if (sectionId === 'welcome') {
            const welcomeUsername = document.getElementById('welcomeUsername');
            const loggedInUser = localStorage.getItem('loggedInUser');
            if (welcomeUsername && loggedInUser) {
                welcomeUsername.textContent = loggedInUser;
            }
        }
    }

    // Show the login section by default
    showSection('login');

    // Toggle password visibility
    function togglePasswordVisibility(toggleId, passwordId) {
        const toggle = document.getElementById(toggleId);
        const password = document.getElementById(passwordId);
        if (toggle && password) {
            toggle.addEventListener('change', function() {
                if (toggle.checked) {
                    password.type = 'text';
                } else {
                    password.type = 'password';
                }
            });
        }
    }

    togglePasswordVisibility('togglePassword', 'password');
    togglePasswordVisibility('toggleNewPassword', 'newPassword');
    togglePasswordVisibility('toggleForgotPassword', 'newForgotPassword');
    togglePasswordVisibility('toggleForgotPassword', 'confirmForgotPassword');

    // Login form submission
    const loginForm = document.getElementById('loginForm');
    if (loginForm) {
        loginForm.addEventListener('submit', function(event) {
            event.preventDefault();
            const username = document.getElementById('username').value;
            const password = document.getElementById('password').value;

            // Retrieve stored accounts from local storage
            const accounts = JSON.parse(localStorage.getItem('accounts')) || [];

            // Check if the entered username and password match any stored account
            const account = accounts.find(acc => acc.username === username && acc.password === password);

            if (account) {
                localStorage.setItem('loggedInUser', username);
                showSection('welcome');
            } else {
                alert('Incorrect username or password!');
            }
        });
    }

    // Create Account form submission
    const createAccountForm = document.getElementById('createAccountForm');
    if (createAccountForm) {
        createAccountForm.addEventListener('submit', function(event) {
            event.preventDefault();
            const newUsername = document.getElementById('newUsername').value;
            const newPassword = document.getElementById('newPassword').value;
            const confirmPassword = document.getElementById('confirmPassword').value;

            if (newPassword !== confirmPassword) {
                alert('Passwords do not match!');
                return;
            }

            // Retrieve stored accounts from local storage
            const accounts = JSON.parse(localStorage.getItem('accounts')) || [];

            // Check if the username already exists
            if (accounts.some(acc => acc.username === newUsername)) {
                alert('Username already exists!');
                return;
            }

            // Add the new account to the accounts array
            accounts.push({ username: newUsername, password: newPassword });

            // Store the updated accounts array in local storage
            localStorage.setItem('accounts', JSON.stringify(accounts));

            alert(`Account created for Username: ${newUsername}`);
            showSection('login');
        });
    }

    // Forgot Password form submission
    const forgotPasswordForm = document.getElementById('forgotPasswordForm');
    if (forgotPasswordForm) {
        forgotPasswordForm.addEventListener('submit', function(event) {
            event.preventDefault();
            const forgotUsername = document.getElementById('forgotUsername').value;
            const newForgotPassword = document.getElementById('newForgotPassword').value;
            const confirmForgotPassword = document.getElementById('confirmForgotPassword').value;

            if (newForgotPassword !== confirmForgotPassword) {
                alert('Passwords do not match!');
                return;
            }

            // Retrieve stored accounts from local storage
            const accounts = JSON.parse(localStorage.getItem('accounts')) || [];

            // Find the account with the provided username
            const accountIndex = accounts.findIndex(acc => acc.username === forgotUsername);

            if (accountIndex === -1) {
                alert('Username not found!');
                return;
            }

            // Update the password for the found account
            accounts[accountIndex].password = newForgotPassword;

            // Store the updated accounts array in local storage
            localStorage.setItem('accounts', JSON.stringify(accounts));

            alert('Password has been reset successfully!');
            showSection('login');
        });
    }

    // Logout function
    function logout() {
        localStorage.removeItem('loggedInUser');
        showSection('login');
    }

    // Expose the showSection and logout functions to the global scope
    window.showSection = showSection;
    window.logout = logout;
});