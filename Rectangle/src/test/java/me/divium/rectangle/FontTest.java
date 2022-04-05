package me.divium.rectangle;

import org.junit.Assert;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class FontTest {

    @Test
    void constructor() {
        Assert.assertThrows(IllegalArgumentException.class, () -> {
           new Font("Sans", new Color(0,0,0), -1);
        });
    }
}