let slideIndex = 0;

// Show the initial slide
function showSlide(index) {
    const slides = document.querySelectorAll(".slide");
    const dots = document.querySelectorAll(".dot");

    if (index >= slides.length) slideIndex = 0; // Loop back to the first slide
    if (index < 0) slideIndex = slides.length - 1; // Loop back to the last slide

    slides.forEach((slide) => {
        slide.classList.remove("active"); // Remove active class for fade effect
    });

    dots.forEach((dot) => dot.classList.remove("active")); // Remove active class from all dots

    slides[slideIndex].classList.add("active"); // Add active class for fade effect
    dots[slideIndex].classList.add("active"); // Highlight the active dot
}

// Change slide manually
function changeSlide(n) {
    slideIndex += n;
    showSlide(slideIndex);
}

// Navigate to a specific slide
function currentSlide(n) {
    slideIndex = n;
    showSlide(slideIndex);
}

// Initialize slideshow
showSlide(slideIndex);