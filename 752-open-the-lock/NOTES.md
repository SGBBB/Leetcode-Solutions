* The motivation to apply 2 - end bfs is that we know start and end point both
* so we search from both ends start as well end eventually we are gonna meet in some midway
* Reaon why its faster is while starting from "0000" we are groing branches exponentially (8^level). Whereas if we have 2 ends moving, the exponent can be reduced to half. Therefore reducing our search time.