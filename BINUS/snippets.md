```mermaid
flowchart LR
    A([Start]) --> B[/Input/Get Date/]
    B --> C{Apakah ini hari Sabtu atau Minggu}
    C -- Yes --> D[Weekend] --> F([End])
    C -- Yes --> E[Weekdays] --> F([End])
```