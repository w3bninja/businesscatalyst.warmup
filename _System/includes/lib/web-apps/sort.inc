{% assign source = '11,2,1' | split: ',' -%}
​
naive sort: `{{ source | sort | json }}`
​
{% capture paddedTemp -%}{% for x in source -%}{{ x | prepend: '00000000' | slice: -8, 8 }},{% endfor -%}{% endcapture -%}
{% assign padded = paddedTemp | split: ',' -%}
​
expected sort: `{{ padded | sort | json }}`
​
<!--output:
​
    naive sort: `[
      "1",
      "11",
      "2"
    ]`
​
​
    expected sort: `[
      "00000001",
      "00000002",
      "00000011"
    ]`
​
-->