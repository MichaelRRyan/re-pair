// When the page scrolls
$(document).scroll(function() {
    // Stick the nav to the page top
    if (pageYOffset > 150) {
        if ($('header').css('position') != 'fixed') {
			$('header').css('position', 'fixed');
            $('header').hide().fadeIn(200);
            $('header').css('background-color', 'rgba(255,255,255,0.8)');
            $('#logo').css('display', 'inherit');
        }
    }
    // Unstick the nav from the page top
    else {
        $('header').css('position','absolute');
        $('header').show();
        $('header').css('background-color', 'rgba(255,255,255,0.2)');
        $('#logo').css('display', 'none');
    }
});

// Scroll Smoothly to the top of the page
$('#about-tab').click(function(event) {
    var scrTo = $('#top').offset().top;
    $('html, body').animate({ scrollTop:scrTo }, 500);
    event.preventDefault();
});

// Scroll Smoothly to the bottom of the page
$('#more-tab').click(function(event) {
    var scrTo = $('#section-social').offset().top;
    $('html, body').animate({ scrollTop:scrTo }, 500);
    event.preventDefault();
});