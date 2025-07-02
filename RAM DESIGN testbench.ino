module tb_sync_ram;

    reg clk;
    reg we;
    reg [3:0] addr;
    reg [7:0] din;
    wire [7:0] dout;

    // Instantiate the RAM
    sync_ram uut (
        .clk(clk),
        .we(we),
        .addr(addr),
        .din(din),
        .dout(dout)
    );

    // Clock Generation
    always #5 clk = ~clk;

    initial begin
        // Initialize inputs
        clk = 0;
        we = 0;
        addr = 0;
        din = 0;

        // Write some data
        #10 we = 1; addr = 4'h1; din = 8'hAA;
        #10 addr = 4'h2; din = 8'h55;
        #10 addr = 4'h3; din = 8'hF0;
        
        // Read data
        #10 we = 0; addr = 4'h1;
        #10 addr = 4'h2;
        #10 addr = 4'h3;

        #10 $finish;
    end
endmodule
