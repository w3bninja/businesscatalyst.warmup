{% if this.latitude != null -%}
    {% if this.longitude != null -%}
    {
        lat: {{this.latitude}},
        lng: {{this.longitude}},
        name: "{{this.name | replace: '"', '''}}",
        address1:"{{this.address1 | replace: '"', '''}}",
        address2: "{{this.city}},{{pin.state}}",
        postalCode: "{{this.zipcode}}" // don't insert comma in the last item of each marker
    }{% if this.counter != pinTotal -%},{% endif -%}
    {% endif -%}
{% endif -%}